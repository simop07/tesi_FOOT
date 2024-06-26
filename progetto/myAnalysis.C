// To compile in SHELL: "g++ myAnalysis.C `root-config --cflags --libs`"

#define myAnalysis_cxx

#include <cstdlib>
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
  gStyle->SetOptStat(10);
  gStyle->SetOptFit(1111);
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(1);
  gStyle->SetStatY(0.9);
  gStyle->SetStatX(0.9);
  gStyle->SetStatW(0.2);
  gStyle->SetStatH(0.2);
  gStyle->SetTitleX(0.5);
  gStyle->SetTitleY(0.98);
  gStyle->SetTitleAlign(23);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleXOffset(1.2f);
  gStyle->SetTitleYOffset(0.8f);
  // gStyle->SetPadTopMargin(-9.);
  // gStyle->SetPadRightMargin(-9.);
  // gStyle->SetPadBottomMargin(-9.);
  // gStyle->SetPadLeftMargin(-9.);
  // gStyle->SetTitleW(0.5f);
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

    nentries = nentries + 1;
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

    //------------------------------starting the analysis here...

    // variables
    double const beta_beam{sqrt(1. - (1. / ((1. + (k_energy_u_beam / u)) *
                                            (1. + (k_energy_u_beam / u)))))};
    double const t_SC_TGT{d_SC_TGT * (1e-2) / (c * beta_beam)};  // in s
    double trackLength{};
    double p{};
    double E_k{};
    double beta{};
    double A1{};
    double A2{};
    double A3{};
    double z_bethe{};
    double z_TW{};

    // A_i loop
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
        z_bethe =
            sqrt(((TWDe1Point->at(GLBtrackTWid->at(GLBtracks_i)) +
                   TWDe2Point->at(GLBtrackTWid->at(GLBtracks_i))) *
                  1e6 * M_u * 4. * Pi() * m_e * epsilon_0 * epsilon_0 * beta *
                  beta) /
                 (dx *
                  (Log((2. * m_e * beta * beta) / (I * (1 - beta * beta))) -
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
        h_E_TOF->Fill(
            (TWTOF->at(GLBtrackTWid->at(GLBtracks_i))) - 1e-9 * t_SC_TGT,
            TWDe1Point->at(GLBtrackTWid->at(GLBtracks_i)) +
                TWDe2Point->at(GLBtrackTWid->at(GLBtracks_i)));

        // fill reconstruction histos
        int zz[8]{1, 2, 3, 4, 5, 6, 7, 8};
        for (int i{}; i != 6; i++) {
          if ((int)TWChargePoint->at(GLBtrackTWid->at(GLBtracks_i)) == zz[i]) {
            switch (i) {
              case 0:
                if (0. < A1 && A1 < 1.5) {
                  h_A1r[i]->Fill(A1);
                }
                if (0. < A2 && A2 < 1.5) {
                  h_A2r[i]->Fill(A2);
                }
                if (0. < A3 && A3 < 1.5) {
                  h_A3r[i]->Fill(A3);
                }
                break;
              case 1:
                if (3.2 < A1 && A1 < 4.8) {
                  h_A1r[i]->Fill(A1);
                }
                if (3.2 < A2 && A2 < 9.) {
                  h_A2r[i]->Fill(A2);
                }
                if (3.2 < A3 && A3 < 9.) {
                  h_A3r[i]->Fill(A3);
                }
                break;
              case 2:
                if (4.8 < A1 && A1 < 8.2) {
                  h_A1r[i]->Fill(A1);
                }
                if (6.5 < A2 && A2 < 7.5) {
                  h_A2r[i]->Fill(A2);
                }
                if (6. < A3 && A3 < 18.) {
                  h_A3r[i]->Fill(A3);
                }
                break;
              case 3:
                if (6.5 < A1 && A1 < 11.5) {
                  h_A1r[i]->Fill(A1);
                }
                if (7. < A2 && A2 < 9.5) {
                  h_A2r[i]->Fill(A2);
                }
                if (8. < A3 && A3 < 20.) {
                  h_A3r[i]->Fill(A3);
                }
                break;
              case 4:
                if (10. < A1 && A1 < 14.5) {
                  h_A1r[i]->Fill(A1);
                }
                if (10. < A2 && A2 < 22.) {
                  h_A2r[i]->Fill(A2);
                }
                if (6. < A3 && A3 < 22.) {
                  h_A3r[i]->Fill(A3);
                }
                break;
              case 5:
                if (10. < A1 && A1 < 16.) {
                  h_A1r[i]->Fill(A1);
                }
                if (0. < A2 && A2 < 16.) {
                  h_A2r[i]->Fill(A2);
                }
                if (6. < A3 && A3 < 24.) {
                  h_A3r[i]->Fill(A3);
                }
                break;
              case 6:
                if (0. < A1 && A1 < 1.5) {
                  h_A1r[i]->Fill(A1);
                }
                if (0. < A2 && A2 < 1.5) {
                  h_A2r[i]->Fill(A2);
                }
                if (0. < A3 && A3 < 1.5) {
                  h_A3r[i]->Fill(A3);
                }
                break;
              case 7:
                if (0. < A1 && A1 < 1.5) {
                  h_A1r[i]->Fill(A1);
                }
                if (0. < A2 && A2 < 1.5) {
                  h_A2r[i]->Fill(A2);
                }
                if (0. < A3 && A3 < 1.5) {
                  h_A3r[i]->Fill(A3);
                }
                break;

              default:
                break;
            }
          }
        }

        // add for debugging
        if (true) {
          std::cout << "event n.: " << ientry << std::endl;
          // std::cout << "\ttrack lenght: " << trackLength
          //           << "\tTOF: " << TWTOF->at(GLBtrackTWid->at(GLBtracks_i))
          //           << std::endl;
          // std::cout << "\t\tp: " << p << "\tbeta: " << beta
          //           << "\tlorentzFactor: " << (1 / (sqrt(1. - beta * beta)))
          //           << "\tbeta_beam: " << beta_beam << std::endl;
          // std::cout << "\t\t\tE_k: " << E_k << std::endl;
          // std::cout << "\t\t\t\tA1: " << A1 << std::endl;
          // std::cout << "\t\t\t\tA2: " << A2 << std::endl;
          // std::cout << "\t\t\t\tA3: " << A3 << std::endl;
          // std::cout << "\t\t\t\t\tz_bethe: " << z_bethe << std::endl;
          // std::cout << "\t\t\t\t\t\tz_TW: " << z_TW << std::endl;
        }
      } else {
        continue;
      }
    }
  }
}

void myAnalysis::BeforeLoop() {
  // creating total histos
  h_A1 = new TH1D("h_A1", "A_1 reconstruction; A_1; Entries", 300, 0., 16.);
  h_A2 = new TH1D("h_A2", "A_2 reconstruction; A_2; Entries", 300, 0., 16.);
  h_A3 = new TH1D("h_A3", "A_3 reconstruction; A_3; Entries", 300, 0., 16.);
  h_z_bethe = new TH1D("h_z_bethe", "z bethe; z; Entries", 300, 0., 12.);
  h_z_TW = new TH1D("h_z", "z TW reconstruction; z; Entries", 13, 0., 12.);
  h_E_TOF =
      new TH2D("h_E_TOF", "#Delta E_{TW} vs TOF; TOF [ns]; Delta E_{TW} [MeV]",
               300, 8., 20., 300, 0., 300.);

  // cosmetics
  h_E_TOF->GetYaxis()->SetTitleOffset(1.2);
  h_E_TOF->GetXaxis()->SetTitleSize(0.04);
  h_E_TOF->GetYaxis()->SetTitleSize(0.04);

  // creating recostruction histos variables
  TString const histname{"h"};
  // const char *element0[8] = {"{}_{1}H", "{}_{2}He", "{}_{3}Li", "{}_{4}Be",
  //                            "{}_{5}B", "{}_{6}C",  "{}_{7}N",  "{}_{8}O"};
  const char *element0[8] = {"{}^{1}_{1}H",  "{}^{4}_{2}He", "{}^{7}_{3}Li",
                             "{}^{9}_{4}Be", "{}^{11}_{5}B", "{}^{12}_{6}C",
                             "{}^{14}_{7}N", "{}^{16}_{8}O"};

  const Double_t xlow[8] = {0., 0., 2., 4., 4., 4., 4., 8.};
  const Double_t xup[8] = {8., 9., 18., 20., 22., 24., 24., 24.};

  for (int i{}; i != 6; i++) {
    // defining offset variables
    int j{i + 8};
    int k{i + 16};

    h_A1r[i] = new TH1D(histname + i, element0[i], 50, xlow[i], xup[i]);
    h_A2r[i] = new TH1D(histname + j, element0[i], 50, xlow[i], xup[i]);
    h_A3r[i] = new TH1D(histname + k, element0[i], 50, xlow[i], xup[i]);

    // cosmetics
    h_A1r[i]->SetMarkerStyle(20);
    h_A1r[i]->SetMarkerSize(0.5);
    h_A1r[i]->SetLineColor(kBlue);
    h_A1r[i]->GetYaxis()->SetTitleOffset(1.2);
    h_A1r[i]->GetXaxis()->SetTitleSize(0.04);
    h_A1r[i]->GetYaxis()->SetTitleSize(0.04);
    h_A1r[i]->GetXaxis()->SetTitle("A_{1}");
    h_A1r[i]->GetYaxis()->SetTitle("Entries");

    h_A2r[i]->SetMarkerStyle(20);
    h_A2r[i]->SetMarkerSize(0.5);
    h_A2r[i]->SetLineColor(kBlue);
    h_A2r[i]->GetYaxis()->SetTitleOffset(1.2);
    h_A2r[i]->GetXaxis()->SetTitleSize(0.04);
    h_A2r[i]->GetYaxis()->SetTitleSize(0.04);
    h_A2r[i]->GetXaxis()->SetTitle("A_{2}");
    h_A2r[i]->GetYaxis()->SetTitle("Entries");

    h_A3r[i]->SetMarkerStyle(20);
    h_A3r[i]->SetMarkerSize(0.5);
    h_A3r[i]->SetLineColor(kBlue);
    h_A3r[i]->GetYaxis()->SetTitleOffset(1.2);
    h_A3r[i]->GetXaxis()->SetTitleSize(0.04);
    h_A3r[i]->GetYaxis()->SetTitleSize(0.04);
    h_A3r[i]->GetXaxis()->SetTitle("A_{3}");
    h_A3r[i]->GetYaxis()->SetTitle("Entries");
  }
}

void myAnalysis::AfterLoop() {
  // creating TFile
  TFile *file = new TFile("analisi/myAnalysis.root", "RECREATE");

  setStyle();

  // defining canvas
  TCanvas *c_A1 = new TCanvas("c_A1", "A_1", 1000, 600);
  TCanvas *c_A2 = new TCanvas("c_A2", "A_2", 1000, 600);
  TCanvas *c_A3 = new TCanvas("c_A3", "A_3", 1000, 600);
  TCanvas *c_z = new TCanvas("c_z", "z", 1000, 600);
  TCanvas *c_A1r = new TCanvas("c_A1r", "A_1r", 1000, 600);
  TCanvas *c_A2r = new TCanvas("c_A2r", "A_2r", 1000, 600);
  TCanvas *c_A3r = new TCanvas("c_A3r", "A_3r", 1000, 600);
  TCanvas *c_E_TOF = new TCanvas("c_E_TOF", "#Delta E vs TOF", 1000, 600);

  // defining fitting functions for total histos
  TF1 *f_z_bethe[8];

  // defining fitting functions for reconstruction histos
  TF1 *f_A1r[8];
  TF1 *f_A2r[8];
  TF1 *f_A3r[8];

  // for bethe function
  TString const funcname_bethe{"f_bethe"};
  const Double_t xlow_bethe[8] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
  const Double_t xup_bethe[8] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5};
  const int mean_value_bethe[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  const Double_t sigma_bethe[8] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};

  // for reconstructed fragments
  TString const funcname{"f"};
  const Double_t xlow[8] = {0.5, 3.5, 6.5, 8.5, 10.5, 11., 4., 8.};
  const Double_t xup[8] = {1.5, 5., 8, 10.5, 11.5, 13., 24., 24.};
  const int mean_value[8] = {1, 4, 7, 9, 11, 12, 14, 16};
  const Double_t sigma[8] = {0.05, 0.1, 0.01, 0.01, 0.01, 0.1, 0.1, 0.1};

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

  c_E_TOF->cd();
  h_E_TOF->Draw("COL2Z");

  // add for debugging
  if (true) {
    TCanvas *c_A1rr[8];
    TCanvas *c_A2rr[8];
    TCanvas *c_A3rr[8];

    TString const canvasname{"c"};
    const char *element0[8] = {"{}_{1}H", "{}_{2}He", "{}_{3}Li", "{}_{4}Be",
                               "{}_{5}B", "{}_{6}C",  "{}_{7}N",  "{}_{8}O"};

    for (int i{}; i != 6; i++) {
      // int j{i + 8};
      int k{i + 16};

      // c_A1rr[i] = new TCanvas(canvasname + i, element0[i], 1000, 600);
      // c_A2rr[i] = new TCanvas(canvasname + j, element0[i], 1000, 600);
      c_A3rr[i] = new TCanvas(canvasname + k, element0[i], 1000, 600);

      // c_A1rr[i]->cd();
      // h_A1r[i]->Draw();

      // c_A2rr[i]->cd();
      // h_A2r[i]->Draw();

      c_A3rr[i]->cd();
      h_A3r[i]->Draw();
    }
  }

  // drawing reconstruction histos on canvas and cosmetics
  for (int i{}; i != 6; i++) {
    // defining offset variables
    int j{i + 8};
    int k{i + 16};

    f_z_bethe[i] =
        new TF1(funcname_bethe + i, "gaus", xlow_bethe[i], xup_bethe[i]);

    f_A1r[i] = new TF1(funcname + i, "gaus", xlow[i], xup[i]);
    f_A2r[i] = new TF1(funcname + j, "gaus", xlow[i], xup[i]);
    f_A3r[i] = new TF1(funcname + k, "gaus", xlow[i], xup[i]);

    // cosmetics
    f_z_bethe[i]->SetLineColor(kRed);
    f_z_bethe[i]->SetLineWidth(3);
    f_z_bethe[i]->SetLineStyle(2);

    f_A1r[i]->SetLineColor(kRed);
    f_A1r[i]->SetLineWidth(3);
    f_A1r[i]->SetLineStyle(2);

    f_A2r[i]->SetLineColor(kRed);
    f_A2r[i]->SetLineWidth(3);
    f_A2r[i]->SetLineStyle(2);

    f_A3r[i]->SetLineColor(kRed);
    f_A3r[i]->SetLineWidth(3);
    f_A3r[i]->SetLineStyle(2);

    // setting parameters' name
    f_z_bethe[i]->SetParNames("Amplitude", "Mean value", "Sigma");
    f_A1r[i]->SetParNames("Amplitude", "Mean value", "Sigma");
    f_A2r[i]->SetParNames("Amplitude", "Mean value", "Sigma");
    f_A3r[i]->SetParNames("Amplitude", "Mean value", "Sigma");

    // setting mean value and sigma
    f_z_bethe[i]->SetParameter(1, mean_value_bethe[i]);
    f_A1r[i]->SetParameter(1, mean_value[i]);
    f_A2r[i]->SetParameter(1, mean_value[i]);
    f_A3r[i]->SetParameter(1, mean_value[i]);

    f_z_bethe[i]->SetParameter(2, sigma_bethe[i]);
    f_A1r[i]->SetParameter(2, sigma[i]);
    f_A2r[i]->SetParameter(2, sigma[i]);
    f_A3r[i]->SetParameter(2, sigma[i]);

    // fitting
    h_z_bethe->Fit(f_z_bethe[i], "R+");
    h_A1r[i]->Fit(f_A1r[i]);
    h_A2r[i]->Fit(f_A2r[i]);
    h_A3r[i]->Fit(f_A3r[i]);
  }

  // dividing reconstruction canvas
  c_A1r->Divide(4, 2);
  c_A2r->Divide(4, 2);
  c_A3r->Divide(4, 2);

  // filling reconstruction canvas
  for (int i{}; i != 6; i++) {
    c_A1r->cd();
    c_A1r->cd(i + 1);
    h_A1r[i]->Draw();
  }
  for (int i{}; i != 6; i++) {
    c_A2r->cd();
    c_A2r->cd(i + 1);
    h_A2r[i]->Draw();
  }
  for (int i{}; i != 6; i++) {
    c_A3r->cd();
    c_A3r->cd(i + 1);
    h_A3r[i]->Draw();
  }

  // add for debugging
  // if (false) {
  //   TCanvas *c_A1rr[8];
  //   TCanvas *c_A2rr[8];
  //   TCanvas *c_A3rr[8];

  //   TString const canvasname{"c"};
  //   const char *element0[8] = {"{}_{1}H", "{}_{2}He", "{}_{3}Li", "{}_{4}Be",
  //                              "{}_{5}B", "{}_{6}C",  "{}_{7}N",  "{}_{8}O"};

  //   for (int i{}; i != 6; i++) {
  //     // int j{i + 8};
  //     int k{i + 16};

  //     // c_A1rr[i] = new TCanvas(canvasname + i, element0[i], 1000, 600);
  //     // c_A2rr[i] = new TCanvas(canvasname + j, element0[i], 1000, 600);
  //     c_A3rr[i] = new TCanvas(canvasname + k, element0[i], 1000, 600);

  //     // c_A1rr[i]->cd();
  //     // h_A1r[i]->Draw();

  //     // c_A2rr[i]->cd();
  //     // h_A2r[i]->Draw();

  //     c_A3rr[i]->cd();
  //     h_A3r[i]->Draw();
  //   }
  // }

  // writing on TFile
  file->cd();
  c_A1->Write();
  c_A2->Write();
  c_A3->Write();
  c_z->Write();
  c_A1r->Write();
  c_A2r->Write();
  c_A3r->Write();
  c_E_TOF->Write();

  file->Close();
}

void myAnalysis::Analysis(Long64_t init = -999, Long64_t nentries = -999) {
  // add benchmark to evaluate performances
  TBenchmark *b = new TBenchmark();

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
  m.Analysis(0, 1e7);

  return EXIT_SUCCESS;
}