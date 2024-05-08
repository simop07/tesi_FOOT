// To compile in SHELL: "g++ myAnalysis.C `root-config --cflags --libs`"

#define myAnalysis_cxx

#include <iostream>

#include "TCanvas.h"
#include "TH2.h"
#include "TStyle.h"
#include "myAnalysis.h"

static Long64_t default_value = -999;
constexpr double c = {3e8};     // in m/s
constexpr double u = {0.9315};  // in GeV

void myAnalysis::PrepareLoop(Long64_t &init = default_value,
                             Long64_t &nentries = default_value) {
  if (nentries ==
      default_value) {  // access to the function with only one argument
    if (init >= 0) {
      nentries = init + 1;
    } else if (init ==
               default_value) {  // access to the function with no argument
      init = 0;
      nentries = fChain->GetEntriesFast();
    } else
      exit(0);
  } else {  // access to the function with both argument (with a range)
    if (nentries < init) exit(0);

    nentries =
        nentries +
        1;  // secondo me questo non fa nulla perché non è che
            // poi la funzione ritorna niente (è void). cioè quello che fa
            // prepare loop è fondamentalmente controllare che il loop non
            // avvenga in maniera errata in un range che è scritto male
  }
  return;
}

void myAnalysis::Loop(Long64_t init = -999, Long64_t nentries = -999) {
  if (fChain == 0) return;

  Long64_t nbytes = 0, nb = 0;
  PrepareLoop(init, nentries);

  for (Long64_t jentry = 0; jentry < nentries; jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    //------------------------------start the analysis here...

    // A loop
    double const number_mass_beam{12.};
    double const k_energy_u_beam{0.200};  // in GeV
    double const beta_beam = sqrt(1. - (1. / ((1. + (k_energy_u_beam / u)) *
                                              (1. + (k_energy_u_beam / u)))));
    double d_SC_TGT{30.};
    double const t_SC_TGT{d_SC_TGT * (1e-2) / (c * beta_beam)};  // in m
    // double distanceFromHit{};
    double trackLength{};
    double p{};
    double E_k{};
    double beta{};

    // A loop
    for (Long64_t GLBtracks_i{}; GLBtracks_i < GLBtracks; GLBtracks_i++) {
      // in GeV
      if ((GLBtrackPx->at(GLBtracks_i)) >= 0 &&
          (GLBtrackPy->at(GLBtracks_i)) >= 0 &&
          (GLBtrackPz->at(GLBtracks_i)) >= 0 &&
          GLBtrackLength->at(GLBtracks_i) >= 0 &&
          GLBtrackCAid->at(GLBtracks_i) >= 0 &&
          GLBtrackTWid->at(GLBtracks_i) >= 0) {
        p = sqrt((GLBtrackPx->at(GLBtracks_i)) * (GLBtrackPx->at(GLBtracks_i)) +
                 (GLBtrackPy->at(GLBtracks_i)) * (GLBtrackPy->at(GLBtracks_i)) +
                 (GLBtrackPz->at(GLBtracks_i)) * (GLBtrackPz->at(GLBtracks_i)));
        trackLength = 1e-2 * GLBtrackLength->at(GLBtracks_i);  // in m

        // in GeV
        E_k = CAenergy->at(GLBtrackCAid->at(GLBtracks_i)) +
              1e-3 * (TWDe1Point->at(GLBtrackTWid->at(GLBtracks_i)) +
                      TWDe2Point->at(GLBtrackTWid->at(GLBtracks_i)));
        beta = (trackLength /
                (c * ((TWTOF->at(GLBtrackTWid->at(GLBtracks_i))) * 1e-9 -
                      t_SC_TGT)));

        h_A1->Fill(p / (u * beta * (1 / (sqrt(1. - beta * beta)))));
        h_A2->Fill(E_k / (u * ((1 / (sqrt(1. - beta * beta))) - 1)));
        h_A3->Fill((p * p - E_k * E_k) / (2 * E_k));

        std::cout << "event n.: " << ientry << std::endl;
        std::cout << "\ttrack lenght: " << trackLength << std::endl;
        std::cout << "\t\tTOF: " << TWTOF->at(GLBtrackTWid->at(GLBtracks_i))
                  << std::endl;
        std::cout << "\t\t\tp: " << p << "\tbeta: " << beta
                  << "\tlorentzFactor: " << (1 / (sqrt(1. - beta * beta)))
                  << "\tbeta beam: " << beta_beam << std::endl;
        std::cout << "\t\t\t\tE_k: " << E_k << std::endl;
        std::cout << "\t\t\t\t\tA1: "
                  << p / (u * beta * (1 / (sqrt(1. - beta * beta))))
                  << std::endl;
        std::cout << "\t\t\t\t\t\tA2: "
                  << E_k / (u * ((1 / (sqrt(1. - beta * beta))) - 1))
                  << std::endl;
        std::cout << "\t\t\t\t\t\t\tA3: " << (p * p - E_k * E_k) / (2 * E_k)
                  << std::endl;
      } else {
        continue;
      }
    }

    /* // INIZIO ESERCIZI

    // EX 1-2
    for (Long64_t pentry = 0; pentry < (long long int)vt_clus_n->size();
         pentry++) {
      Long64_t clus_counter = 0;
      for (Long64_t clentry = clus_counter;
           clentry < (clus_counter + vt_clus_n->at(pentry)); clentry++)
    { histo_xy_clus->Fill(vt_clus_x->at(clentry),
    vt_clus_y->at(clentry));
    histo_xyz_clus->Fill(vt_clus_x->at(clentry), vt_clus_y->at(clentry),
    vt_clus_z->at(clentry));
      }
      clus_counter += vt_clus_n->at(pentry);
    }

    // EX 3
    for (Long64_t ventry = 0; ventry < vertex_n; ventry++) {
      Long64_t clus_counter = 0;
      for (Long64_t track = 0; track < vt_trk_n->at(ventry); track++) {
        for (Long64_t centry = clus_counter;
             centry < (clus_counter + vt_trk_clus_n->at(track));
    centry++) { if (vt_trk_n->at(ventry) == 1) {
            histo_xyz_trk_clus->Fill(vt_trk_clus_x->at(centry),
                                     vt_trk_clus_y->at(centry),
                                     vt_trk_clus_z->at(centry));
          }
        }
        clus_counter += vt_trk_clus_n->at(track);
      }
    }

    // EX 4
    for (Long64_t twentry = 0; twentry < TWPoints; twentry++) {
      double distanceFromHit = 0.;
      for (Long64_t ventry = 0; ventry < vertex_n; ventry++) {
        Long64_t clus_counter = 0;
        for (Long64_t tentry = 0; tentry < vt_trk_n->at(ventry);
    tentry++) { for (Long64_t centry = clus_counter; centry <
    (clus_counter + vt_trk_clus_n->at(tentry)); centry++) { if
    (vt_trk_n->at(ventry) == 1
    && (distanceFromHit = sqrt((TWXPoint->at(twentry) -
                           vt_trk_projTW->at(ventry).X()) *
                              (TWXPoint->at(twentry) -
                               vt_trk_projTW->at(ventry).X()) +
                          (TWYPoint->at(twentry) -
                           vt_trk_projTW->at(ventry).Y()) *
                              (TWYPoint->at(twentry) -
                               vt_trk_projTW->at(ventry).Y())) <= 4)) {
              histo_xyz_trk_clus_match->Fill(vt_trk_clus_x->at(centry),
                                             vt_trk_clus_y->at(centry),
                                             vt_trk_clus_z->at(centry));
            }
          }
          clus_counter += vt_trk_clus_n->at(tentry);
        }
      }
    }

    // FINE ESERCIZI

    // distribution of vtx points
    // filliamo tutti i punti di vertice dell'esperimento FOOT. per ogni
    // evento, pesco tutti i vertex point che ci sono e all'interno
    dell'histo
    // li mettiamo tutti. il loop è un for che agisce per ogni evento.
    for (int i = 0; i < vertex_n; i++) {  // loop on every vtx point
      histo_vtxpoint->Fill(vertex_x->at(i), vertex_y->at(i),
    vertex_z->at(i));
    }

    // distribution of TW points
    double distanceFromHit = 0.;
    for (Long64_t twentry = 0; twentry < TWPoints;
         twentry++)  // loop on twpoints
    {
      histo_tw->Fill(TWXPoint->at(twentry),
                     TWYPoint->at(twentry));  // plot all TWPoints(X,Y)
      histo_tw_3d->Fill(TWXPoint->at(twentry), TWYPoint->at(twentry),
                        TWZPoint->at(twentry));
      // rilascio di energia del primo strato di barre
      histo_de_vs_tof->Fill(TWDe1Point->at(twentry),
    TWTOF->at(twentry));

      for (Long64_t vtxentry = 0; vtxentry < vertex_n;
           vtxentry++) {  // loop on vtx points
        for (Long64_t vtentry = 0; vtentry < vt_trk_n->at(vtxentry);
             vtentry++)  // loop on tracks for every tw point
        {
          // distance from the projection of the vtx track to TW and
    TWpoint distanceFromHit = sqrt( (TWXPoint->at(twentry) -
    vt_trk_projTW->at(vtentry).X()) * (TWXPoint->at(twentry) -
    vt_trk_projTW->at(vtentry).X()) + (TWYPoint->at(twentry) -
    vt_trk_projTW->at(vtentry).Y()) * (TWYPoint->at(twentry) -
    vt_trk_projTW->at(vtentry).Y()));

          if (distanceFromHit <=
              4.)  // conservative threshold to match a twpoint
                   // to a vtx track for global tracking
          {
            histo_tw_matched->Fill(TWXPoint->at(twentry),
                                   TWYPoint->at(twentry));
          }
        }
      }
    }
    // DA OGNI TRACCIA, che è l'oggetto vertex track, prendo la sua
    proiezione
    // al tofwall e misuro la distanza. se la distanza è minore di 4,
    allora
    // riempio l'istogramma poi magari posso anche fare un test di chi
    quadro
    //

    //------------------ print chi2 of vtx tracks, taking care on how
    vector
    // are
    // filled
    bool debug = true;
    if (debug) {
      std::cout << "event n: " << ev << std::endl;
      std::cout << "total number of vtx point: " << vertex_n <<
    std::endl; Long64_t track_counter = 0; for (int i = 0; i < vertex_n;
    i++) {  // loop on every vtx point std::cout << "vertex point n: "
    << i << std::endl; std::cout << "tracks n: " << vt_trk_n->at(i) <<
    std::endl; for (int j = 0; j < vt_trk_n->at(i); j++) { std::cout <<
    "track n: " << j << std::endl; std::cout
              << "chi square: " << vt_trk_chi2->at(track_counter + j)
              << std::endl;  // trackcounter is an offset to take out
    track info
                             // not from the beginning of the vector
        }
        track_counter += vt_trk_n->at(i);
      }
    } */
  }
}

// nella funzione qui sotto accade questo. ogni cluster è un blocco di
// pixel accesi, ho più cluster per ogni piano. in questo caso il
// ragionamento è questo: per ogni evento ho più piani del VTX che si
// accendono. per ogni piano posso avere più cluster. con
// vt_clus_n->size() trovo quanti piani ho per quell'evento. vt_clus_n è
// un vettore proprio perché (n, m) n è il numero di cluster nel 1°
// piano, m è il numero di cluster nel 2° piano e così via). quindi se
// per esempio ho che un evento ha acceso 4 piani, avrò che la size del
// vettore sopra citato sarà pari a 4. poi ogni piano è stato denominato
// con pentry, quindi parleremo del piano p-esimo. nel piano p-esimo
// potremmo trovare il numero di cluster. per ogni cluster posso trovare
// il numero di hit. vt_clus_tot_hits è proprio il vettore che contiene
// il numero di hit per ogni cluster. ad esempio, vt_clus_n=(2,1,3) sta
// a significare che nel primo piano ho 2 cluster, nel secondo 1 cluster
// e nel terzo 3 cluster. il vettore vt_clus_tot_hits potrebbe essere
// vt_clus_tot_hits(11,2,  33,  12, 10, 7), ossia che il primo cluster
// ha acceso 11 pixel, il secondo 2 pixel (e con questi due finiamo
// l'elenco dei cluster nel primo piano), il terzo cluster (del secondo
// piano) ha acceso 33 pixel e così via. allora, visto che il vettore
// vt_clus_tot_hits possiede elementi che potrebbero far parte di piani
// differenti, per fare in modo di selezionare solo gli elementi del
// piano p-esimo, si implementa l'algoritmo in basso (vedi clus_counter)
void myAnalysis::PrintVtTrackInfo(Long64_t init = -999,
                                  Long64_t nentries = -999) {
  if (fChain == 0) return;

  Long64_t nbytes = 0, nb = 0;
  PrepareLoop(init, nentries);

  for (Long64_t jentry = init; jentry < nentries; jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    std::cout << "Event: " << ientry << std::endl;

    std::cout << "	total n° of vtx points: " << vertex_n << std::endl;
    for (Long64_t ventry = 0; ventry < vertex_n; ventry++) {
      std::cout << "	VTX point n° " << ventry << std::endl;
      std::cout << "	VTX point position: " << vertex_x->at(ventry) << " "
                << vertex_y->at(ventry) << " " << vertex_z->at(ventry)
                << std::endl;
      std::cout << "		total n° of reconstructed tracks: "
                << vt_trk_n->at(ventry) << std::endl;
      // std::cout << "	total n° of clusters (of all tracks): " <<
      // vt_trk_clus_x->size() << std::endl;
      Long64_t clus_counter = 0;
      for (Long64_t tentry = 0; tentry < vt_trk_n->at(ventry); tentry++) {
        std::cout << "			track n° " << tentry << std::endl;
        std::cout << "			origin position: "
                  << vt_trk_origin->at(tentry).X() << " "
                  << vt_trk_origin->at(tentry).Y() << " "
                  << vt_trk_origin->at(tentry).Z() << std::endl;
        std::cout << "			projection to TW: "
                  << vt_trk_projTW->at(tentry).X() << " "
                  << vt_trk_projTW->at(tentry).Y() << " "
                  << vt_trk_projTW->at(tentry).Z() << std::endl;
        std::cout << "			n° of clusters: "
                  << vt_trk_clus_n->at(tentry) << std::endl;
        for (Long64_t centry = clus_counter;
             centry < (clus_counter + vt_trk_clus_n->at(tentry)); centry++) {
          std::cout << "				cluster n° " << centry
                    << std::endl;
          std::cout << "					n° of hits "
                    << vt_trk_clus_tot_hits->at(centry) << std::endl;
          std::cout << "					position: "
                    << vt_trk_clus_x->at(centry) << " "
                    << vt_trk_clus_y->at(centry) << " "
                    << vt_trk_clus_z->at(centry) << std::endl;
        }
        clus_counter += vt_trk_clus_n->at(tentry);
      }
    }
  }
}

void myAnalysis::PrintVtClusInfo(Long64_t init = -999,
                                 Long64_t nentries = -999) {
  if (fChain == 0) return;

  Long64_t nbytes = 0, nb = 0;
  PrepareLoop(init, nentries);

  for (Long64_t jentry = init; jentry < nentries; jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    // uso ientry (anche se secondo me in questo caso basta
    // jentry visto che la chain corrisponde all'unico Tree che
    // abbiamo a disposizione) per far riferimento all'evento del
    // nostro Tree
    std::cout << "Event: " << ientry << std::endl;
    std::cout << " n° of VT planes: " << vt_clus_n->size() << std::endl;
    Long64_t clus_counter = 0;  // è un numero inizializzato a 0
    for (Long64_t pentry = 0; pentry < (long long int)vt_clus_n->size();
         pentry++) {
      std::cout << " VT plane: " << pentry << std::endl;
      std::cout << "   n° of clusters: " << vt_clus_n->at(pentry) << std::endl;

      // l'indice c è quello che viagga nel sottorange del piano p-esimo
      for (Long64_t clentry = clus_counter;
           clentry < (clus_counter + vt_clus_n->at(pentry)); clentry++) {
        std::cout << "      clus n° " << clentry << std::endl;
        std::cout << "      n° of hits: " << vt_clus_tot_hits->at(clentry);
        std::cout << "		position: " << vt_clus_x->at(clentry) << " "
                  << vt_clus_y->at(clentry) << " " << vt_clus_z->at(clentry)
                  << std::endl;
        std::cout << " MC ID: " << vt_clus_MC->at(clentry * 5)
                  << " MC charge: " << vt_clus_MC->at(clentry * 5 + 1)
                  << " MC MID: " << vt_clus_MC->at(clentry * 5 + 2)
                  << " MC init pos (Z): " << vt_clus_MC->at(clentry * 5 + 3)
                  << " MC init momentum: " << vt_clus_MC->at(clentry * 5 + 4)
                  << std::endl;
      }
      // pentry sarebbe la posizione p-esima nel vettore vt_clus_n. il
      // metodo vector::at restituisce una referenza all'elemento che si
      // trova nella posizione p-esima (pentry) all'interno del vettore
      // vt_clus_n. in questo modo, quando facciamo il loop sopra,
      // stiamo selezionando solo le hit appartenenti al piano p-esimo

      // NOTA: chiaramente si conta da 0

      // variabile di offset
      clus_counter += vt_clus_n->at(pentry);
    }
  }
}

void myAnalysis::PrintTwPointInfo(Long64_t init = -999,
                                  Long64_t nentries = -999) {
  if (fChain == 0) return;

  Long64_t nbytes = 0, nb = 0;
  PrepareLoop(init, nentries);

  for (Long64_t jentry = init; jentry < nentries; jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    std::cout << "Event: " << ientry << std::endl;
    std::cout << "n° of TWpoints: " << TWPoints << std::endl;

    for (Long64_t twentry = 0; twentry < TWPoints; twentry++) {
      std::cout << "   TWpoint n° " << twentry << std::endl;
      std::cout << "      Charge: " << TWChargePoint->at(twentry) << std::endl;
      std::cout << "      Position: " << TWXPoint->at(twentry) << " "
                << TWYPoint->at(twentry) << " " << TWZPoint->at(twentry)
                << std::endl;
      std::cout << "      Energy loss1: " << TWDe1Point->at(twentry)
                << std::endl;
      std::cout << "      Energy loss2: " << TWDe2Point->at(twentry)
                << std::endl;
      std::cout << "      ToF: " << TWTOF->at(twentry) << std::endl;
    }
  }
}

// qui vengono inizializzati alcuni istogrammi
void myAnalysis::BeforeLoop() {
  // booking of the histograms

  h_A1 =
      new TH1D("h_A1", "A_1 reconstruction cluster distribution; A_1; Entries",
               100, 0., 40.);
  h_A2 =
      new TH1D("h_A2", "A_2 reconstruction cluster distribution; A_1; Entries",
               100, 0., 40.);
  h_A3 =
      new TH1D("h_A3", "A_3 reconstruction cluster distribution; A_1; Entries",
               100, 0., 40.);
  /* histo_xy_clus =
      new TH2D("histo_xy_clus", "XY cluster distribution; X [cm]; Y
  [cm]", 10, -20., 20., 10, -20., 20.); histo_xyz_clus = new
  TH3D("histo_xyz_clus", "XYZ cluster distribution; X[cm]; Y[cm];
  Z[cm]", 10, -20., 20., 10, -20, 20., 10, -20., 20.);
  histo_xyz_trk_clus = new TH3D("histo_xyz_trk_clus", "XYZ cluster track
  distribution; X[cm]; Y[cm]; Z[cm]", 10, -20., 20., 10, -20, 20., 10,
  -20., 20.); histo_xyz_trk_clus_match = new
  TH3D("histo_xyz_trk_clus_match", "XYZ cluster track distribution
  match; X[cm]; Y[cm]; Z[cm]", 10, -20., 20., 10, -20, 20., 10,
  -20., 20.); histo_tw = new TH2D("TW points distribution", "TW points
  distribution; X [cm]; Y [cm]", 10, -20, 20., 10, -20, 20.);
  histo_tw_matched = new TH2D("TW points distribution - VTX matched",
  "TW points distribution - VTX matched; X [cm]; Y [cm]", 10, -20, 20.,
  10, -20, 20.); histo_de_vs_tof = new TH2D( "TW dE vs tof", "TW dE vs
  tof points distribution; TOF [ns]; dE [MeV]", 100, 0., 20., 100, 0.,
  200.); histo_tw_3d = new TH3D("TW points distribution 3d", "TW points
  distribution 3d; X [cm]; Y [cm]; Z[cm]", 10, -20, 20, 10, -20, 20, 10,
  180, 190); histo_vtxpoint = new TH3D("vtx point distribution 3d", "VTX
  point distributzion; X[cm]; Y[cm]; Z[cm]", 10, -2, 2, 10, -1, 1, 10,
  -1, 1); */
}

// nell'afterloop vogliamo stampare gli istogrammi fillati nel loop
void myAnalysis::AfterLoop() {
  // plot histos on a canvas
  TCanvas *c_A1 = new TCanvas("c_A1", "A_1", 1000, 600);
  h_A1->Draw();
  TCanvas *c_A2 = new TCanvas("c_A2", "A_2", 1000, 600);
  h_A2->Draw();
  TCanvas *c_A3 = new TCanvas("c_A3", "A_3", 1000, 600);
  h_A3->Draw();

  /* TCanvas *c = new TCanvas("c", "Exercises", 2000, 1000);
  c->Divide(2, 2);
  c->cd(1);
  histo_xy_clus->Draw("colz");
  c->cd(2);
  histo_xyz_clus->Draw();
  c->cd(3);
  histo_xyz_trk_clus->Draw();
  c->cd(4);
  histo_xyz_trk_clus_match->Draw();

  TCanvas *c1 = new TCanvas("c1", "TW Analysis", 2000, 1000);
  c1->Divide(2, 1);
  c1->cd(1);
  histo_tw->Draw();
  c1->cd(2);
  histo_tw_matched->Draw();

  TCanvas *c2 = new TCanvas("c2", "TW 3d", 2000, 1000);
  histo_tw_3d->Draw();

  TCanvas *c3 = new TCanvas("c3", "vtxpoint", 2000, 1000);
  histo_vtxpoint->Draw();

  TCanvas *c4 = new TCanvas("c4", "TW dE vs TOF", 2000, 1000);
  histo_de_vs_tof->Draw("colz"); */

  // delete c1, histo_tw, histo_tw_matched;
}

// contiene beforeloop, loop e afterloop
void myAnalysis::Analysis(Long64_t init = -999, Long64_t nentries = -999) {
  std::cout << "Analysis starting..." << std::endl;
  BeforeLoop();
  Loop(init, nentries);
  AfterLoop();
  std::cout << "Analysis done" << std::endl;
}

int main() {
  myAnalysis m;
  m.Analysis(0, 1e3);

  return EXIT_SUCCESS;
}