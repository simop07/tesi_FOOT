// To compile in SHELL: "g++ myAnalysis.C `root-config --cflags --libs`"

#define myAnalysis_cxx

#include <iostream>

#include "TBenchmark.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH2.h"
#include "TLatex.h"
#include "TMath.h"
#include "TPad.h"
#include "TROOT.h"
#include "TString.h"
#include "TStyle.h"
#include "constants.h"
#include "myAnalysis.h"

static Long64_t default_value = -999;

void myAnalysis::setStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0000000);
  gStyle->SetOptFit(0000);
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(1);
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.025);
  gStyle->SetTitleX(-.1f);
  gStyle->SetTitleY(0.97f);
  gStyle->SetTitleW(1.2f);
  gStyle->SetTitleBorderSize(0);
  // gStyle->SetTitleXOffset(1.2f);
  // gStyle->SetTitleYOffset(0.8f);
}

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
    using namespace constants;
    using namespace TMath;

    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    //------------------------------start the analysis here...

    // variables
    double const beta_beam{sqrt(1. - (1. / ((1. + (k_energy_u_beam / u)) *
                                            (1. + (k_energy_u_beam / u)))))};
    double const t_SC_TGT{d_SC_TGT * (1e-2) / (c * beta_beam)};  // in s
    // double distanceFromHit{};
    double trackLength{};
    double p{};
    double E_k{};
    double beta{};
    double A1{};
    double A2{};
    double A3{};
    double z_bethe{};
    double z_TW{};

    // A loop
    for (Long64_t GLBtracks_i{}; GLBtracks_i < GLBtracks; GLBtracks_i++) {
      if ((GLBtrackPx->at(GLBtracks_i)) >= 0 &&
          (GLBtrackPy->at(GLBtracks_i)) >= 0 &&
          (GLBtrackPz->at(GLBtracks_i)) >= 0 &&
          GLBtrackLength->at(GLBtracks_i) >= 0 &&
          GLBtrackCAid->at(GLBtracks_i) >= 0 &&
          GLBtrackTWid->at(GLBtracks_i) >= 0 &&
          TWChargePoint->at(GLBtrackTWid->at(GLBtracks_i)) >= 0) {
        // in GeV
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

        // A_i definitions
        A1 = p / (u * beta * (1 / (sqrt(1. - beta * beta))));
        A2 = E_k / (u * ((1 / (sqrt(1. - beta * beta))) - 1));
        A3 = (p * p - E_k * E_k) / (2 * E_k);

        // z_bethe reconstruction
        z_bethe = sqrt(((TWDe1Point->at(GLBtrackTWid->at(GLBtracks_i)) +
                         TWDe2Point->at(GLBtrackTWid->at(GLBtracks_i))) *
                        1e6 * M_u * 4. * Pi() * m_e * epsilon_0 * epsilon_0 *
                        beta * beta) /
                       (dx *
                        Log((2. * m_e * beta * beta) / (I * (1 - beta * beta)) -
                            beta * beta) *
                        q_e * q_e * N_a * rho * Z));

        // z_TW reconstruction
        z_TW = TWChargePoint->at(GLBtrackTWid->at(GLBtracks_i));

        // fill total histos
        h_A1->Fill(A1);
        h_A2->Fill(A2);
        h_A3->Fill(A3);
        h_z_bethe->Fill(z_bethe);
        h_z_TW->Fill(z_TW);

        // fill reconstruction histos
        int zz[8]{1, 2, 3, 4, 5, 6, 7, 8};
        for (int i{}; i != 6; i++) {
          if ((int)TWChargePoint->at(GLBtrackTWid->at(GLBtracks_i)) == zz[i]) {
            h_A1_r[i]->Fill(A1);
            h_A2_r[i]->Fill(A2);
            h_A3_r[i]->Fill(A3);
          }
        }

        // add for debugging
        if (false) {
          std::cout << "event n.: " << ientry << std::endl;
          std::cout << "\ttrack lenght: " << trackLength
                    << "\tTOF: " << TWTOF->at(GLBtrackTWid->at(GLBtracks_i))
                    << std::endl;
          std::cout << "\t\tp: " << p << "\tbeta: " << beta
                    << "\tlorentzFactor: " << (1 / (sqrt(1. - beta * beta)))
                    << "\tbeta_beam: " << beta_beam << std::endl;
          std::cout << "\t\t\tE_k: " << E_k << std::endl;
          std::cout << "\t\t\t\tA1: " << A1 << std::endl;
          std::cout << "\t\t\t\tA2: " << A2 << std::endl;
          std::cout << "\t\t\t\tA3: " << A3 << std::endl;
          std::cout << "\t\t\t\t\tz_bethe: " << z_bethe << std::endl;
          std::cout << "\t\t\t\t\t\tz_TW: " << z_TW << std::endl;
        }
      } else {
        continue;
      }
    }
  }
}

void myAnalysis::BeforeLoop() {
  // creating total histos
  h_A1 = new TH1D("h_A1", "A_1 reconstruction; A_1; Entries", 1000, 0., 16.);
  h_A2 = new TH1D("h_A2", "A_2 reconstruction; A_2; Entries", 1000, 0., 16.);
  h_A3 = new TH1D("h_A3", "A_3 reconstruction; A_3; Entries", 1000, 0., 16.);
  h_z_bethe = new TH1D("h_z_bethe", "z bethe; z; Entries", 1000, 0., 12.);
  h_z_TW = new TH1D("h_z", "z TW reconstruction; z; Entries", 13, 0., 12.);

  // creating recostruction histos
  TString const histname{"h"};
  const char *element[8] = {"{}^{1}_{1}H",  "{}^{4}_{2}He", "{}^{7}_{3}Li",
                            "{}^{9}_{4}Be", "{}^{11}_{5}B", "{}^{12}_{6}C",
                            "{}^{14}_{7}N", "{}^{16}_{8}O"};

  const Double_t xlow[8] = {0., 0., 2., 4., 4., 4., 4., 8.};
  const Double_t xup[8] = {3., 9., 18., 20., 22., 24., 24., 24.};

  for (int i{}; i != 6; i++) {
    // defining offset variables
    int j{i + 8};
    int k{i + 16};

    h_A1_r[i] = new TH1D(histname + i, element[i], 1000, xlow[i], xup[i]);
    h_A2_r[i] = new TH1D(histname + j, element[i], 1000, xlow[i], xup[i]);
    h_A3_r[i] = new TH1D(histname + k, element[i], 1000, xlow[i], xup[i]);

    // cosmetics
    h_A1_r[i]->SetMarkerStyle(20);
    h_A1_r[i]->SetMarkerSize(0.5);
    h_A1_r[i]->SetLineColor(kBlue);
    h_A1_r[i]->GetYaxis()->SetTitleOffset(1.2);
    h_A1_r[i]->GetXaxis()->SetTitleSize(0.04);
    h_A1_r[i]->GetYaxis()->SetTitleSize(0.04);
    h_A1_r[i]->GetXaxis()->SetTitle("A_{1}");
    h_A1_r[i]->GetYaxis()->SetTitle("Entries");

    h_A2_r[i]->SetMarkerStyle(20);
    h_A2_r[i]->SetMarkerSize(0.5);
    h_A2_r[i]->SetLineColor(kBlue);
    h_A2_r[i]->GetYaxis()->SetTitleOffset(1.2);
    h_A2_r[i]->GetXaxis()->SetTitleSize(0.04);
    h_A2_r[i]->GetYaxis()->SetTitleSize(0.04);
    h_A2_r[i]->GetXaxis()->SetTitle("A_{2}");
    h_A2_r[i]->GetYaxis()->SetTitle("Entries");

    h_A3_r[i]->SetMarkerStyle(20);
    h_A3_r[i]->SetMarkerSize(0.5);
    h_A3_r[i]->SetLineColor(kBlue);
    h_A3_r[i]->GetYaxis()->SetTitleOffset(1.2);
    h_A3_r[i]->GetXaxis()->SetTitleSize(0.04);
    h_A3_r[i]->GetYaxis()->SetTitleSize(0.04);
    h_A3_r[i]->GetXaxis()->SetTitle("A_{3}");
    h_A3_r[i]->GetYaxis()->SetTitle("Entries");
  }

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

void myAnalysis::AfterLoop() {
  // creating TFile
  TFile *file = new TFile("analisi/myAnalysis.root", "RECREATE");

  // defining canvas
  TCanvas *c_A1 = new TCanvas("c_A1", "A_1", 1000, 600);
  TCanvas *c_A2 = new TCanvas("c_A2", "A_2", 1000, 600);
  TCanvas *c_A3 = new TCanvas("c_A3", "A_3", 1000, 600);
  TCanvas *c_z = new TCanvas("c_z", "z", 1000, 600);
  TCanvas *c_A1_r = new TCanvas("c_A1_r", "A_1_r", 1000, 600);
  TCanvas *c_A2_r = new TCanvas("c_A2_r", "A_2_r", 1000, 600);
  TCanvas *c_A3_r = new TCanvas("c_A3_r", "A_3_r", 1000, 600);

  // dividing reconstruction canvas
  c_A1_r->Divide(4, 2);
  c_A2_r->Divide(4, 2);
  c_A3_r->Divide(4, 2);

  // defining fitting functions for total histos
  TF1 *f_z_bethe[8];

  // defining fitting functions for reconstruction histos
  TF1 *f_A1_r[8];
  TF1 *f_A2_r[8];
  TF1 *f_A3_r[8];

  // for bethe function
  TString const funcname_bethe{"f_bethe"};
  const Double_t xlow_bethe[8] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
  const Double_t xup_bethe[8] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5};
  const int mean_value_bethe[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  const Double_t sigma_bethe[8] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};

  // for reconstructed fragments
  TString const funcname{"f"};
  const Double_t xlow[8] = {0., 0., 2., 4., 4., 4., 4., 8.};
  const Double_t xup[8] = {3., 9., 18., 20., 22., 24., 24., 24.};
  const int mean_value[8] = {1, 4, 7, 9, 11, 12, 14, 16};
  const Double_t sigma[8] = {0.1, 0.1, 1., 1., 1., 1., 1., 1.};

  for (int i{}; i != 6; i++) {
    // defining offset variables
    int j{i + 8};
    int k{i + 16};

    f_z_bethe[i] =
        new TF1(funcname_bethe + i, "gaus", xlow_bethe[i], xup_bethe[i]);

    f_A1_r[i] = new TF1(funcname + i, "gaus", xlow[i], xup[i]);
    f_A2_r[i] = new TF1(funcname + j, "gaus", xlow[i], xup[i]);
    f_A3_r[i] = new TF1(funcname + k, "gaus", xlow[i], xup[i]);

    // cosmetics
    f_z_bethe[i]->SetLineColor(kRed);
    f_z_bethe[i]->SetLineWidth(3);
    f_z_bethe[i]->SetLineStyle(2);

    f_A1_r[i]->SetLineColor(kRed);
    f_A1_r[i]->SetLineWidth(3);
    f_A1_r[i]->SetLineStyle(2);

    f_A2_r[i]->SetLineColor(kRed);
    f_A2_r[i]->SetLineWidth(3);
    f_A2_r[i]->SetLineStyle(2);

    f_A3_r[i]->SetLineColor(kRed);
    f_A3_r[i]->SetLineWidth(3);
    f_A3_r[i]->SetLineStyle(2);

    // setting parameters' name
    f_z_bethe[i]->SetParNames("Amplitude", "Mean value", "Sigma");
    f_A1_r[i]->SetParNames("Amplitude", "Mean value", "Sigma");
    f_A2_r[i]->SetParNames("Amplitude", "Mean value", "Sigma");
    f_A3_r[i]->SetParNames("Amplitude", "Mean value", "Sigma");

    // setting mean value and sigma
    f_z_bethe[i]->SetParameter(1, mean_value_bethe[i]);
    f_A1_r[i]->SetParameter(1, mean_value[i]);
    f_A2_r[i]->SetParameter(1, mean_value[i]);
    f_A3_r[i]->SetParameter(1, mean_value[i]);

    f_z_bethe[i]->SetParameter(2, sigma_bethe[i]);
    f_A1_r[i]->SetParameter(2, sigma[i]);
    f_A2_r[i]->SetParameter(2, sigma[i]);
    f_A3_r[i]->SetParameter(2, sigma[i]);

    // fitting
    h_z_bethe->Fit(f_z_bethe[i], "R+");
    h_A1_r[i]->Fit(f_A1_r[i]);
    h_A2_r[i]->Fit(f_A2_r[i]);
    h_A3_r[i]->Fit(f_A3_r[i]);

    // filling reconstruction canvas
    c_A1_r->cd();
    c_A1_r->cd(i + 1);
    h_A1_r[i]->Draw();

    c_A2_r->cd();
    c_A2_r->cd(i + 1);
    h_A2_r[i]->Draw();

    c_A3_r->cd();
    c_A3_r->cd(i + 1);
    h_A3_r[i]->Draw();
  }

  // add for debugging
  if (false) {
    TCanvas *c_A1_rr[8];
    TCanvas *c_A2_rr[8];
    TCanvas *c_A3_rr[8];

    TString const canvasname{"c"};
    const char *element[8] = {"{}^{1}_{1}H",  "{}^{4}_{2}He", "{}^{7}_{3}Li",
                              "{}^{9}_{4}Be", "{}^{11}_{5}B", "{}^{12}_{6}C",
                              "{}^{14}_{7}N", "{}^{16}_{8}O"};
    for (int i{}; i != 6; i++) {
      int j{i + 8};
      int k{i + 16};

      c_A1_rr[i] = new TCanvas(canvasname + i, element[i], 1000, 600);
      c_A2_rr[i] = new TCanvas(canvasname + j, element[i], 1000, 600);
      c_A3_rr[i] = new TCanvas(canvasname + k, element[i], 1000, 600);

      c_A1_rr[i]->cd();
      h_A1_r[i]->Draw();

      c_A2_rr[i]->cd();
      h_A2_r[i]->Draw();

      c_A3_rr[i]->cd();
      h_A3_r[i]->Draw();
    }
  }

  // drawing total histos on canvas
  c_A1->cd();
  h_A1->Draw();

  c_A2->cd();
  h_A2->Draw();

  c_A3->cd();
  h_A3->Draw();

  c_z->cd();
  h_z_bethe->Draw();
  h_z_TW->Draw("SAME");

  // writing on TFile
  file->cd();
  c_A1->Write();
  c_A2->Write();
  c_A3->Write();
  c_z->Write();
  c_A1_r->Write();
  c_A2_r->Write();
  c_A3_r->Write();

  file->Close();
}

void myAnalysis::Analysis(Long64_t init = -999, Long64_t nentries = -999) {
  TBenchmark *b = new TBenchmark();

  setStyle();

  b->Start("Analysis duration");
  std::cout << "Analysis starting..." << std::endl;
  BeforeLoop();
  Loop(init, nentries);
  AfterLoop();
  std::cout << "Analysis done" << std::endl;
  b->Show("Analysis duration");
}

int main() {
  myAnalysis m;
  m.Analysis(0, 100000);

  return EXIT_SUCCESS;
}