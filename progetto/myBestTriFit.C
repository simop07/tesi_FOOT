#include <vector>

#include "TCanvas.h"
#include "TCutG.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TH2.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TMultiGraph.h"
#include "TPad.h"
#include "TROOT.h"
#include "TStyle.h"

void setFitStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(10);
  gStyle->SetOptFit(0);
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(1);
  gStyle->SetTitleBorderSize(0);
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

void myBestTriFit() {
  // Loading ROOT File
  TFile *file1 = new TFile("analisi/myAnalysis.root", "READ");

  // Creating ROOT File
  TFile *file2 = new TFile("analisi/myBestTriFit.root", "RECREATE");

  // Defining canvas for reading 2D histo
  TCanvas *c0 = (TCanvas *)file1->Get("c_21cor0");
  TCanvas *c1 = (TCanvas *)file1->Get("c_21cor1");
  TCanvas *c2 = (TCanvas *)file1->Get("c_21cor2");
  TCanvas *c3 = (TCanvas *)file1->Get("c_21cor3");
  TCanvas *c4 = (TCanvas *)file1->Get("c_21cor4");
  TCanvas *c5 = (TCanvas *)file1->Get("c_21cor5");
  TCanvas *c6 = (TCanvas *)file1->Get("c_31cor6");
  TCanvas *c7 = (TCanvas *)file1->Get("c_31cor7");
  TCanvas *c8 = (TCanvas *)file1->Get("c_31cor8");
  TCanvas *c9 = (TCanvas *)file1->Get("c_31cor9");
  TCanvas *c10 = (TCanvas *)file1->Get("c_31cor10");
  TCanvas *c11 = (TCanvas *)file1->Get("c_31cor11");
  TCanvas *c12 = (TCanvas *)file1->Get("c_32cor12");
  TCanvas *c13 = (TCanvas *)file1->Get("c_32cor13");
  TCanvas *c14 = (TCanvas *)file1->Get("c_32cor14");
  TCanvas *c15 = (TCanvas *)file1->Get("c_32cor15");
  TCanvas *c16 = (TCanvas *)file1->Get("c_32cor16");
  TCanvas *c17 = (TCanvas *)file1->Get("c_32cor17");

  // Reading histograms in ROOT File
  TH2D *h_Acor0 = (TH2D *)c0->GetPrimitive("h_Acor0");
  TH2D *h_Acor1 = (TH2D *)c1->GetPrimitive("h_Acor1");
  TH2D *h_Acor2 = (TH2D *)c2->GetPrimitive("h_Acor2");
  TH2D *h_Acor3 = (TH2D *)c3->GetPrimitive("h_Acor3");
  TH2D *h_Acor4 = (TH2D *)c4->GetPrimitive("h_Acor4");
  TH2D *h_Acor5 = (TH2D *)c5->GetPrimitive("h_Acor5");
  TH2D *h_Acor6 = (TH2D *)c6->GetPrimitive("h_Acor6");
  TH2D *h_Acor7 = (TH2D *)c7->GetPrimitive("h_Acor7");
  TH2D *h_Acor8 = (TH2D *)c8->GetPrimitive("h_Acor8");
  TH2D *h_Acor9 = (TH2D *)c9->GetPrimitive("h_Acor9");
  TH2D *h_Acor10 = (TH2D *)c10->GetPrimitive("h_Acor10");
  TH2D *h_Acor11 = (TH2D *)c11->GetPrimitive("h_Acor11");
  TH2D *h_Acor12 = (TH2D *)c12->GetPrimitive("h_Acor12");
  TH2D *h_Acor13 = (TH2D *)c13->GetPrimitive("h_Acor13");
  TH2D *h_Acor14 = (TH2D *)c14->GetPrimitive("h_Acor14");
  TH2D *h_Acor15 = (TH2D *)c15->GetPrimitive("h_Acor15");
  TH2D *h_Acor16 = (TH2D *)c16->GetPrimitive("h_Acor16");
  TH2D *h_Acor17 = (TH2D *)c17->GetPrimitive("h_Acor17");

  setFitStyle();

  // Defining canvas for cutted 1D histo
  TCanvas *c_cut0 = new TCanvas("c_cut0", "c_cut0", 1000, 600);
  TCanvas *c_cut1 = new TCanvas("c_cut1", "c_cut1", 1000, 600);
  TCanvas *c_cut2 = new TCanvas("c_cut2", "c_cut2", 1000, 600);
  TCanvas *c_cut3 = new TCanvas("c_cut3", "c_cut3", 1000, 600);
  TCanvas *c_cut4 = new TCanvas("c_cut4", "c_cut4", 1000, 600);
  TCanvas *c_cut5 = new TCanvas("c_cut5", "c_cut5", 1000, 600);
  TCanvas *c_cut6 = new TCanvas("c_cut6", "c_cut6", 1000, 600);
  TCanvas *c_cut7 = new TCanvas("c_cut7", "c_cut7", 1000, 600);
  TCanvas *c_cut8 = new TCanvas("c_cut8", "c_cut8", 1000, 600);
  TCanvas *c_cut9 = new TCanvas("c_cut9", "c_cut9", 1000, 600);
  TCanvas *c_cut10 = new TCanvas("c_cut10", "c_cut10", 1000, 600);
  TCanvas *c_cut11 = new TCanvas("c_cut11", "c_cut11", 1000, 600);
  TCanvas *c_cut12 = new TCanvas("c_cut12", "c_cut12", 1000, 600);
  TCanvas *c_cut13 = new TCanvas("c_cut13", "c_cut13", 1000, 600);
  TCanvas *c_cut14 = new TCanvas("c_cut14", "c_cut14", 1000, 600);
  TCanvas *c_cut15 = new TCanvas("c_cut15", "c_cut15", 1000, 600);
  TCanvas *c_cut16 = new TCanvas("c_cut16", "c_cut16", 1000, 600);
  TCanvas *c_cut17 = new TCanvas("c_cut17", "c_cut17", 1000, 600);

  // divide canvas
  c_cut0->Divide(2, 1);
  c_cut1->Divide(2, 1);
  c_cut2->Divide(2, 1);
  c_cut3->Divide(2, 1);
  c_cut4->Divide(2, 1);
  c_cut5->Divide(2, 1);
  c_cut6->Divide(2, 1);
  c_cut7->Divide(2, 1);
  c_cut8->Divide(2, 1);
  c_cut9->Divide(2, 1);
  c_cut10->Divide(2, 1);
  c_cut11->Divide(2, 1);
  c_cut12->Divide(2, 1);
  c_cut13->Divide(2, 1);
  c_cut14->Divide(2, 1);
  c_cut15->Divide(2, 1);
  c_cut16->Divide(2, 1);
  c_cut17->Divide(2, 1);

  // defining arrays for cuts
  const Double_t x0[4] = {0.267606, 3.55399, 2.99844, 0.267606};
  const Double_t y0[4] = {0.227513, 3.17989, 3.50794, 0.227513};

  const Double_t x1[5] = {1.94718, 7, 6.28697, 2.02641, 1.94718};
  const Double_t y1[5] = {1.625, 5.83929, 6.8631, 2.27976, 1.625};

  const Double_t x2[5] = {3.77152, 8.98279, 7.94992, 3.61502, 3.77152};
  const Double_t y2[5] = {3.36508, 8.25397, 8.2963, 3.83069, 3.36508};

  const Double_t x3[5] = {6.241, 11.2488, 9.66823, 6.05321, 6.241};
  const Double_t y3[5] = {5.55556, 10.2328, 10.2116, 6.12698, 5.55556};

  const Double_t x4[5] = {6.64437, 13.0704, 11.2746, 7.61268, 6.64437};
  const Double_t y4[5] = {5.89286, 11.5119, 11.4405, 7.63095, 5.89286};

  const Double_t x5[5] = {6.42958, 15.2911, 13.0219, 6.80125, 6.42958};
  const Double_t y5[5] = {5.57407, 12.7169, 14.3307, 6.39418, 5.57407};

  const Double_t x6[6] = {5.83412, 11.7496, 9.01095, 8.41628, 6.11581, 5.83412};
  const Double_t y6[6] = {5.1746, 10.4233, 10.4233, 7.60847, 7.31217, 5.1746};

  const Double_t x7[5] = {6.72711, 2.39613, 2.55458, 6.48944, 6.72711};
  const Double_t y7[5] = {5.82738, 2.01786, 3.27976, 6.50595, 5.82738};

  const Double_t x8[5] = {3.92801, 10, 8.68545, 4.47574, 3.92801};
  const Double_t y8[5] = {3.74603, 8.95238, 8.91005, 4.7619, 3.74603};

  const Double_t x9[8] = {6.05321, 11.2645, 10.8732, 8.87011,
                          8.35368, 7.16432, 6.11581, 6.05321};
  const Double_t y9[8] = {5.4709,  10.127,  11.4815, 9.21693,
                          7.62963, 8.39153, 5.68254, 5.4709};

  const Double_t x10[5] = {6.50352, 13.2817, 12.4014, 6.96127, 6.50352};
  const Double_t y10[5] = {6.72619, 12.1071, 12.9167, 7.55952, 6.72619};

  const Double_t x11[5] = {6.11659, 13.6283, 13.2958, 5.97966, 6.11659};
  const Double_t y11[5] = {5.62698, 11.8968, 14.8598, 6.12963, 5.62698};

  const Double_t x12[5] = {0.752739, 3.62441, 3.08451, 0.611894, 0.752739};
  const Double_t y12[5] = {0.513227, 2.96825, 3.58201, 0.851852, 0.513227};

  const Double_t x13[5] = {2.3257, 6.6831, 6.01408, 2.04401, 2.3257};
  const Double_t y13[5] = {1.8869, 5.54167, 6.57738, 2.55357, 1.8869};

  const Double_t x14[5] = {4.25665, 9.64006, 8.09077, 4.1784, 4.25665};
  const Double_t y14[5] = {3.59788, 8.71958, 8.88889, 4.61376, 3.59788};

  const Double_t x15[5] = {6.02191, 10.9984, 9.88732, 5.84977, 6.02191};
  const Double_t y15[5] = {5.72487, 9.85185, 11.1217, 6.67725, 5.72487};

  const Double_t x16[5] = {6.64437, 12.419, 11.2923, 6.73239, 6.64437};
  const Double_t y16[5] = {7.13095, 11.4405, 12.4643, 8.22619, 7.13095};

  const Double_t x17[5] = {5.97966, 13.6088, 11.8091, 6.07746, 5.97966};
  const Double_t y17[5] = {5.36243, 11.5, 14.8598, 7.32011, 5.36243};

  // defining cuts
  TCutG *myCut0 = new TCutG("myCut0", 4, x0, y0);
  TCutG *myCut1 = new TCutG("myCut1", 5, x1, y1);
  TCutG *myCut2 = new TCutG("myCut2", 5, x2, y2);
  TCutG *myCut3 = new TCutG("myCut3", 5, x3, y3);
  TCutG *myCut4 = new TCutG("myCut4", 5, x4, y4);
  TCutG *myCut5 = new TCutG("myCut5", 5, x5, y5);
  TCutG *myCut6 = new TCutG("myCut6", 6, x6, y6);
  TCutG *myCut7 = new TCutG("myCut7", 5, x7, y7);
  TCutG *myCut8 = new TCutG("myCut8", 5, x8, y8);
  TCutG *myCut9 = new TCutG("myCut9", 8, x9, y9);
  TCutG *myCut10 = new TCutG("myCut10", 5, x10, y10);
  TCutG *myCut11 = new TCutG("myCut11", 5, x11, y11);
  TCutG *myCut12 = new TCutG("myCut12", 5, x12, y12);
  TCutG *myCut13 = new TCutG("myCut13", 5, x13, y13);
  TCutG *myCut14 = new TCutG("myCut14", 5, x14, y14);
  TCutG *myCut15 = new TCutG("myCut15", 5, x15, y15);
  TCutG *myCut16 = new TCutG("myCut16", 5, x16, y16);
  TCutG *myCut17 = new TCutG("myCut17", 5, x17, y17);

  // creating and filling 1D histos
  // histo0
  TH1D *h21_1_0 = new TH1D("h21_1_0", "H; A_{1}; Occorrenze", 300, 0., 8.);
  h21_1_0 = h_Acor0->ProjectionX("h21_1_0", 0, -1, "[myCut0]");

  TH1D *h0_1 = new TH1D("h0_1", "H; A_{1}; Occorrenze", 300, 0., 8.);
  h0_1 = h_Acor0->ProjectionX("h0_1", 0, -1);
  h0_1->SetMarkerStyle(20);
  h0_1->SetMarkerSize(0.5);
  h0_1->SetLineColor(kBlue);
  h0_1->SetLineWidth(2);
  h0_1->GetYaxis()->SetTitleOffset(1.5);
  h0_1->GetXaxis()->SetTitleSize(0.04);
  h0_1->GetYaxis()->SetTitleSize(0.04);

  TH1D *h21_2_0 = new TH1D("h21_2_0", "H; A_{2}; Occorrenze", 300, 0., 8.);
  h21_2_0 = h_Acor0->ProjectionY("h21_2_0", 0, -1, "[myCut0]");

  TH1D *h0_2 = new TH1D("h0_2", "H; A_{2}; Occorrenze", 300, 0., 8.);
  h0_2 = h_Acor0->ProjectionY("h0_2", 0, -1);
  h0_2->SetMarkerStyle(20);
  h0_2->SetMarkerSize(0.5);
  h0_2->SetLineColor(kBlue);
  h0_2->SetLineWidth(2);
  h0_2->GetYaxis()->SetTitleOffset(1.5);
  h0_2->GetXaxis()->SetTitleSize(0.04);
  h0_2->GetYaxis()->SetTitleSize(0.04);

  TH1D *h31_1_0 = new TH1D("h31_1_0", "H; A_{1}; Occorrenze", 300, 0., 8.);
  h31_1_0 = h_Acor6->ProjectionX("h31_1_0", 0, -1, "[myCut6]");

  TH1D *h31_3_0 = new TH1D("h31_3_0", "H; A_{3}; Occorrenze", 300, 0., 8.);
  h31_3_0 = h_Acor6->ProjectionY("h31_3_0", 0, -1, "[myCut6]");

  TH1D *h0_3 = new TH1D("h0_3", "H; A_{3}; Occorrenze", 300, 0., 8.);
  h0_3 = h_Acor6->ProjectionY("h0_3", 0, -1);
  h0_3->SetMarkerStyle(20);
  h0_3->SetMarkerSize(0.5);
  h0_3->SetLineColor(kBlue);
  h0_3->SetLineWidth(2);
  h0_3->GetYaxis()->SetTitleOffset(1.5);
  h0_3->GetXaxis()->SetTitleSize(0.04);
  h0_3->GetYaxis()->SetTitleSize(0.04);

  TH1D *h32_2_0 = new TH1D("h32_2_0", "H; A_{2}; Occorrenze", 300, 0., 8.);
  h32_2_0 = h_Acor12->ProjectionX("h32_2_0", 0, -1, "[myCut12]");

  TH1D *h32_3_0 = new TH1D("h32_3_0", "H; A_{3}; Occorrenze", 300, 0., 8.);
  h32_3_0 = h_Acor12->ProjectionY("h32_3_0", 0, -1, "[myCut12]");

  // histo1
  TH1D *h21_1_1 = new TH1D("h21_1_1", "He; A_{1}; Occorrenze", 300, 0., 9.);
  h21_1_1 = h_Acor1->ProjectionX("h21_1_1", 0, -1, "[myCut1]");

  TH1D *h1_1 = new TH1D("h1_1", "He; A_{1}; Occorrenze", 300, 0., 8.);
  h1_1 = h_Acor1->ProjectionX("h1_1", 0, -1);
  h1_1->SetMarkerStyle(20);
  h1_1->SetMarkerSize(0.5);
  h1_1->SetLineColor(kBlue);
  h1_1->SetLineWidth(2);
  h1_1->GetYaxis()->SetTitleOffset(1.5);
  h1_1->GetXaxis()->SetTitleSize(0.04);
  h1_1->GetYaxis()->SetTitleSize(0.04);

  TH1D *h21_2_1 = new TH1D("h21_2_1", "He; A_{2}; Occorrenze", 300, 0., 9.);
  h21_2_1 = h_Acor1->ProjectionY("h21_2_1", 0, -1, "[myCut1]");

  TH1D *h1_2 = new TH1D("h1_2", "He; A_{2}; Occorrenze", 300, 0., 8.);
  h1_2 = h_Acor1->ProjectionY("h1_2", 0, -1);
  h1_2->SetMarkerStyle(20);
  h1_2->SetMarkerSize(0.5);
  h1_2->SetLineColor(kBlue);
  h1_2->SetLineWidth(2);
  h1_2->GetYaxis()->SetTitleOffset(1.5);
  h1_2->GetXaxis()->SetTitleSize(0.04);
  h1_2->GetYaxis()->SetTitleSize(0.04);

  TH1D *h31_1_1 = new TH1D("h31_1_1", "He; A_{1}; Occorrenze", 300, 0., 9.);
  h31_1_1 = h_Acor7->ProjectionX("h31_1_1", 0, -1, "[myCut7]");

  TH1D *h31_3_1 = new TH1D("h31_3_1", "He; A_{3}; Occorrenze", 300, 0., 9.);
  h31_3_1 = h_Acor7->ProjectionY("h31_3_1", 0, -1, "[myCut7]");

  TH1D *h1_3 = new TH1D("h1_3", "He; A_{3}; Occorrenze", 300, 0., 8.);
  h1_3 = h_Acor7->ProjectionY("h1_3", 0, -1);
  h1_3->SetMarkerStyle(20);
  h1_3->SetMarkerSize(0.5);
  h1_3->SetLineColor(kBlue);
  h1_3->SetLineWidth(2);
  h1_3->GetYaxis()->SetTitleOffset(1.5);
  h1_3->GetXaxis()->SetTitleSize(0.04);
  h1_3->GetYaxis()->SetTitleSize(0.04);

  TH1D *h32_2_1 = new TH1D("h32_2_1", "He; A_{2}; Occorrenze", 300, 0., 9.);
  h32_2_1 = h_Acor13->ProjectionX("h32_2_1", 0, -1, "[myCut13]");

  TH1D *h32_3_1 = new TH1D("h32_3_1", "He; A_{3}; Occorrenze", 300, 0., 9.);
  h32_3_1 = h_Acor13->ProjectionY("h32_3_1", 0, -1, "[myCut13]");

  // histo2
  TH1D *h21_1_2 = new TH1D("h21_1_2", "Li; A_{1}; Occorrenze", 300, 2., 18.);
  h21_1_2 = h_Acor2->ProjectionX("h21_1_2", 0, -1, "[myCut2]");

  TH1D *h2_1 = new TH1D("h2_1", "Li; A_{1}; Occorrenze", 300, 0., 8.);
  h2_1 = h_Acor2->ProjectionX("h2_1", 0, -1);
  h2_1->SetMarkerStyle(20);
  h2_1->SetMarkerSize(0.5);
  h2_1->SetLineColor(kBlue);
  h2_1->SetLineWidth(2);
  h2_1->GetYaxis()->SetTitleOffset(1.5);
  h2_1->GetXaxis()->SetTitleSize(0.04);
  h2_1->GetYaxis()->SetTitleSize(0.04);

  TH1D *h21_2_2 = new TH1D("h21_2_2", "Li; A_{2}; Occorrenze", 300, 2., 18.);
  h21_2_2 = h_Acor2->ProjectionY("h21_2_2", 0, -1, "[myCut2]");

  TH1D *h2_2 = new TH1D("h2_2", "Li; A_{2}; Occorrenze", 300, 0., 8.);
  h2_2 = h_Acor2->ProjectionY("h2_2", 0, -1);
  h2_2->SetMarkerStyle(20);
  h2_2->SetMarkerSize(0.5);
  h2_2->SetLineColor(kBlue);
  h2_2->SetLineWidth(2);
  h2_2->GetYaxis()->SetTitleOffset(1.5);
  h2_2->GetXaxis()->SetTitleSize(0.04);
  h2_2->GetYaxis()->SetTitleSize(0.04);

  TH1D *h31_1_2 = new TH1D("h31_1_2", "Li; A_{1}; Occorrenze", 300, 2., 18.);
  h31_1_2 = h_Acor8->ProjectionX("h31_1_2", 0, -1, "[myCut8]");

  TH1D *h31_3_2 = new TH1D("h31_3_2", "Li; A_{3}; Occorrenze", 300, 2., 18.);
  h31_3_2 = h_Acor8->ProjectionY("h31_3_2", 0, -1, "[myCut8]");

  TH1D *h2_3 = new TH1D("h2_3", "Li; A_{3}; Occorrenze", 300, 0., 8.);
  h2_3 = h_Acor8->ProjectionY("h2_3", 0, -1);
  h2_3->SetMarkerStyle(20);
  h2_3->SetMarkerSize(0.5);
  h2_3->SetLineColor(kBlue);
  h2_3->SetLineWidth(2);
  h2_3->GetYaxis()->SetTitleOffset(1.5);
  h2_3->GetXaxis()->SetTitleSize(0.04);
  h2_3->GetYaxis()->SetTitleSize(0.04);

  TH1D *h32_2_2 = new TH1D("h32_2_2", "Li; A_{2}; Occorrenze", 300, 2., 18.);
  h32_2_2 = h_Acor14->ProjectionX("h32_2_2", 0, -1, "[myCut14]");

  TH1D *h32_3_2 = new TH1D("h32_3_2", "Li; A_{3}; Occorrenze", 300, 2., 18.);
  h32_3_2 = h_Acor14->ProjectionY("h32_3_2", 0, -1, "[myCut14]");

  // histo3
  TH1D *h21_1_3 = new TH1D("h21_1_3", "Be; A_{1}; Occorrenze", 300, 4., 20.);
  h21_1_3 = h_Acor3->ProjectionX("h21_1_3", 0, -1, "[myCut3]");

  TH1D *h3_1 = new TH1D("h3_1", "Be; A_{1}; Occorrenze", 300, 0., 8.);
  h3_1 = h_Acor3->ProjectionX("h3_1", 0, -1);
  h3_1->SetMarkerStyle(20);
  h3_1->SetMarkerSize(0.5);
  h3_1->SetLineColor(kBlue);
  h3_1->SetLineWidth(2);
  h3_1->GetYaxis()->SetTitleOffset(1.2);
  h3_1->GetXaxis()->SetTitleSize(0.04);
  h3_1->GetYaxis()->SetTitleSize(0.04);

  TH1D *h21_2_3 = new TH1D("h21_2_3", "Be; A_{2}; Occorrenze", 300, 4., 20.);
  h21_2_3 = h_Acor3->ProjectionY("h21_2_3", 0, -1, "[myCut3]");

  TH1D *h3_2 = new TH1D("h3_2", "Be; A_{2}; Occorrenze", 300, 0., 8.);
  h3_2 = h_Acor3->ProjectionY("h3_2", 0, -1);
  h3_2->SetMarkerStyle(20);
  h3_2->SetMarkerSize(0.5);
  h3_2->SetLineColor(kBlue);
  h3_2->SetLineWidth(2);
  h3_2->GetYaxis()->SetTitleOffset(1.2);
  h3_2->GetXaxis()->SetTitleSize(0.04);
  h3_2->GetYaxis()->SetTitleSize(0.04);

  TH1D *h31_1_3 = new TH1D("h31_1_3", "Be; A_{1}; Occorrenze", 300, 4., 20.);
  h31_1_3 = h_Acor9->ProjectionX("h31_1_3", 0, -1, "[myCut9]");

  TH1D *h31_3_3 = new TH1D("h31_3_3", "Be; A_{3}; Occorrenze", 300, 4., 20.);
  h31_3_3 = h_Acor9->ProjectionY("h31_3_3", 0, -1, "[myCut9]");

  TH1D *h3_3 = new TH1D("h3_3", "Be; A_{3}; Occorrenze", 300, 0., 8.);
  h3_3 = h_Acor9->ProjectionY("h3_3", 0, -1);
  h3_3->SetMarkerStyle(20);
  h3_3->SetMarkerSize(0.5);
  h3_3->SetLineColor(kBlue);
  h3_3->SetLineWidth(2);
  h3_3->GetYaxis()->SetTitleOffset(1.2);
  h3_3->GetXaxis()->SetTitleSize(0.04);
  h3_3->GetYaxis()->SetTitleSize(0.04);

  TH1D *h32_2_3 = new TH1D("h32_2_3", "Be; A_{2}; Occorrenze", 300, 4., 20.);
  h32_2_3 = h_Acor15->ProjectionX("h32_2_3", 0, -1, "[myCut15]");

  TH1D *h32_3_3 = new TH1D("h32_3_3", "Be; A_{3}; Occorrenze", 300, 4., 20.);
  h32_3_3 = h_Acor15->ProjectionY("h32_3_3", 0, -1, "[myCut15]");

  // histo4
  TH1D *h21_1_4 = new TH1D("h21_1_4", "B; A_{1}; Occorrenze", 300, 4., 22.);
  h21_1_4 = h_Acor4->ProjectionX("h21_1_4", 0, -1, "[myCut4]");

  TH1D *h4_1 = new TH1D("h4_1", "B; A_{1}; Occorrenze", 300, 0., 8.);
  h4_1 = h_Acor4->ProjectionX("h4_1", 0, -1);
  h4_1->SetMarkerStyle(20);
  h4_1->SetMarkerSize(0.5);
  h4_1->SetLineColor(kBlue);
  h4_1->SetLineWidth(2);
  h4_1->GetYaxis()->SetTitleOffset(1.5);
  h4_1->GetXaxis()->SetTitleSize(0.04);
  h4_1->GetYaxis()->SetTitleSize(0.04);

  TH1D *h21_2_4 = new TH1D("h21_2_4", "B; A_{2}; Occorrenze", 300, 4., 22.);
  h21_2_4 = h_Acor4->ProjectionY("h21_2_4", 0, -1, "[myCut4]");

  TH1D *h4_2 = new TH1D("h4_2", "B; A_{2}; Occorrenze", 300, 0., 8.);
  h4_2 = h_Acor4->ProjectionY("h4_2", 0, -1);
  h4_2->SetMarkerStyle(20);
  h4_2->SetMarkerSize(0.5);
  h4_2->SetLineColor(kBlue);
  h4_2->SetLineWidth(2);
  h4_2->GetYaxis()->SetTitleOffset(1.5);
  h4_2->GetXaxis()->SetTitleSize(0.04);
  h4_2->GetYaxis()->SetTitleSize(0.04);

  TH1D *h31_1_4 = new TH1D("h31_1_4", "B; A_{1}; Occorrenze", 300, 4., 22.);
  h31_1_4 = h_Acor10->ProjectionX("h31_1_4", 0, -1, "[myCut10]");

  TH1D *h31_3_4 = new TH1D("h31_3_4", "B; A_{3}; Occorrenze", 300, 4., 22.);
  h31_3_4 = h_Acor10->ProjectionY("h31_3_4", 0, -1, "[myCut10]");

  TH1D *h4_3 = new TH1D("h4_3", "B; A_{3}; Occorrenze", 300, 0., 8.);
  h4_3 = h_Acor10->ProjectionY("h4_3", 0, -1);
  h4_3->SetMarkerStyle(20);
  h4_3->SetMarkerSize(0.5);
  h4_3->SetLineColor(kBlue);
  h4_3->SetLineWidth(2);
  h4_3->GetYaxis()->SetTitleOffset(1.5);
  h4_3->GetXaxis()->SetTitleSize(0.04);
  h4_3->GetYaxis()->SetTitleSize(0.04);

  TH1D *h32_2_4 = new TH1D("h32_2_4", "B; A_{2}; Occorrenze", 300, 4., 22.);
  h32_2_4 = h_Acor16->ProjectionX("h32_2_4", 0, -1, "[myCut16]");

  TH1D *h32_3_4 = new TH1D("h32_3_4", "B; A_{3}; Occorrenze", 300, 4., 22.);
  h32_3_4 = h_Acor16->ProjectionY("h32_3_4", 0, -1, "[myCut16]");

  // histo5
  TH1D *h21_1_5 = new TH1D("h21_1_5", "C; A_{1}; Occorrenze", 300, 4., 24.);
  h21_1_5 = h_Acor5->ProjectionX("h21_1_5", 0, -1, "[myCut5]");

  TH1D *h5_1 = new TH1D("h5_1", "C; A_{1}; Occorrenze", 300, 0., 8.);
  h5_1 = h_Acor5->ProjectionX("h5_1", 0, -1);
  h5_1->SetMarkerStyle(20);
  h5_1->SetMarkerSize(0.5);
  h5_1->SetLineColor(kBlue);
  h5_1->SetLineWidth(2);
  h5_1->GetYaxis()->SetTitleOffset(1.5);
  h5_1->GetXaxis()->SetTitleSize(0.04);
  h5_1->GetYaxis()->SetTitleSize(0.04);

  TH1D *h21_2_5 = new TH1D("h21_2_5", "C; A_{2}; Occorrenze", 300, 4., 24.);
  h21_2_5 = h_Acor5->ProjectionY("h21_2_5", 0, -1, "[myCut5]");

  TH1D *h5_2 = new TH1D("h5_2", "C; A_{2}; Occorrenze", 300, 0., 8.);
  h5_2 = h_Acor5->ProjectionY("h5_2", 0, -1);
  h5_2->SetMarkerStyle(20);
  h5_2->SetMarkerSize(0.5);
  h5_2->SetLineColor(kBlue);
  h5_2->SetLineWidth(2);
  h5_2->GetYaxis()->SetTitleOffset(1.5);
  h5_2->GetXaxis()->SetTitleSize(0.04);
  h5_2->GetYaxis()->SetTitleSize(0.04);

  TH1D *h31_1_5 = new TH1D("h31_1_5", "C; A_{1}; Occorrenze", 300, 4., 24.);
  h31_1_5 = h_Acor11->ProjectionX("h31_1_5", 0, -1, "[myCut11]");

  TH1D *h31_3_5 = new TH1D("h31_3_5", "C; A_{3}; Occorrenze", 300, 4., 24.);
  h31_3_5 = h_Acor11->ProjectionY("h31_3_5", 0, -1, "[myCut11]");

  TH1D *h5_3 = new TH1D("h5_3", "C; A_{3}; Occorrenze", 300, 0., 8.);
  h5_3 = h_Acor5->ProjectionY("h5_3", 0, -1);
  h5_3->SetMarkerStyle(20);
  h5_3->SetMarkerSize(0.5);
  h5_3->SetLineColor(kBlue);
  h5_3->SetLineWidth(2);
  h5_3->GetYaxis()->SetTitleOffset(1.5);
  h5_3->GetXaxis()->SetTitleSize(0.04);
  h5_3->GetYaxis()->SetTitleSize(0.04);

  TH1D *h32_2_5 = new TH1D("h32_2_5", "C; A_{2}; Occorrenze", 300, 4., 24.);
  h32_2_5 = h_Acor17->ProjectionX("h32_2_5", 0, -1, "[myCut17]");

  TH1D *h32_3_5 = new TH1D("h32_3_5", "C; A_{3}; Occorrenze", 300, 4., 24.);
  h32_3_5 = h_Acor17->ProjectionY("h32_3_5", 0, -1, "[myCut17]");

  // histo cosmetics
  // histo0
  h21_1_0->SetMarkerStyle(20);
  h21_1_0->SetMarkerSize(1.5);
  h21_1_0->GetYaxis()->SetTitleOffset(1.2);
  h21_1_0->GetXaxis()->SetTitleSize(0.04);
  h21_1_0->GetYaxis()->SetTitleSize(0.04);

  h21_1_0->SetMarkerStyle(20);
  h21_1_0->SetMarkerSize(1.5);
  h21_1_0->GetYaxis()->SetTitleOffset(1.2);
  h21_1_0->GetXaxis()->SetTitleSize(0.04);
  h21_1_0->GetYaxis()->SetTitleSize(0.04);

  h31_1_0->SetMarkerStyle(20);
  h31_1_0->SetMarkerSize(1.5);
  h31_1_0->GetYaxis()->SetTitleOffset(1.2);
  h31_1_0->GetXaxis()->SetTitleSize(0.04);
  h31_1_0->GetYaxis()->SetTitleSize(0.04);

  h31_3_0->SetMarkerStyle(20);
  h31_3_0->SetMarkerSize(1.5);
  h31_3_0->GetYaxis()->SetTitleOffset(1.2);
  h31_3_0->GetXaxis()->SetTitleSize(0.04);
  h31_3_0->GetYaxis()->SetTitleSize(0.04);

  h32_2_0->SetMarkerStyle(20);
  h32_2_0->SetMarkerSize(1.5);
  h32_2_0->GetYaxis()->SetTitleOffset(1.2);
  h32_2_0->GetXaxis()->SetTitleSize(0.04);
  h32_2_0->GetYaxis()->SetTitleSize(0.04);

  h32_3_0->SetMarkerStyle(20);
  h32_3_0->SetMarkerSize(1.5);
  h32_3_0->GetYaxis()->SetTitleOffset(1.2);
  h32_3_0->GetXaxis()->SetTitleSize(0.04);
  h32_3_0->GetYaxis()->SetTitleSize(0.04);

  // histo1
  h21_1_1->SetMarkerStyle(20);
  h21_1_1->SetMarkerSize(1.5);
  h21_1_1->GetYaxis()->SetTitleOffset(1.2);
  h21_1_1->GetXaxis()->SetTitleSize(0.04);
  h21_1_1->GetYaxis()->SetTitleSize(0.04);

  h21_2_1->SetMarkerStyle(20);
  h21_2_1->SetMarkerSize(1.5);
  h21_2_1->GetYaxis()->SetTitleOffset(1.2);
  h21_2_1->GetXaxis()->SetTitleSize(0.04);
  h21_2_1->GetYaxis()->SetTitleSize(0.04);

  h31_1_1->SetMarkerStyle(20);
  h31_1_1->SetMarkerSize(1.5);
  h31_1_1->GetYaxis()->SetTitleOffset(1.2);
  h31_1_1->GetXaxis()->SetTitleSize(0.04);
  h31_1_1->GetYaxis()->SetTitleSize(0.04);

  h31_3_1->SetMarkerStyle(20);
  h31_3_1->SetMarkerSize(1.5);
  h31_3_1->GetYaxis()->SetTitleOffset(1.2);
  h31_3_1->GetXaxis()->SetTitleSize(0.04);
  h31_3_1->GetYaxis()->SetTitleSize(0.04);

  h32_2_1->SetMarkerStyle(20);
  h32_2_1->SetMarkerSize(1.5);
  h32_2_1->GetYaxis()->SetTitleOffset(1.2);
  h32_2_1->GetXaxis()->SetTitleSize(0.04);
  h32_2_1->GetYaxis()->SetTitleSize(0.04);

  h32_3_1->SetMarkerStyle(20);
  h32_3_1->SetMarkerSize(1.5);
  h32_3_1->GetYaxis()->SetTitleOffset(1.2);
  h32_3_1->GetXaxis()->SetTitleSize(0.04);
  h32_3_1->GetYaxis()->SetTitleSize(0.04);

  // histo2
  h21_1_2->SetMarkerStyle(20);
  h21_1_2->SetMarkerSize(1.5);
  h21_1_2->GetYaxis()->SetTitleOffset(1.2);
  h21_1_2->GetXaxis()->SetTitleSize(0.04);
  h21_1_2->GetYaxis()->SetTitleSize(0.04);

  h21_2_2->SetMarkerStyle(20);
  h21_2_2->SetMarkerSize(1.5);
  h21_2_2->GetYaxis()->SetTitleOffset(1.2);
  h21_2_2->GetXaxis()->SetTitleSize(0.04);
  h21_2_2->GetYaxis()->SetTitleSize(0.04);

  h31_1_2->SetMarkerStyle(20);
  h31_1_2->SetMarkerSize(1.5);
  h31_1_2->GetYaxis()->SetTitleOffset(1.2);
  h31_1_2->GetXaxis()->SetTitleSize(0.04);
  h31_1_2->GetYaxis()->SetTitleSize(0.04);

  h31_3_2->SetMarkerStyle(20);
  h31_3_2->SetMarkerSize(1.5);
  h31_3_2->GetYaxis()->SetTitleOffset(1.2);
  h31_3_2->GetXaxis()->SetTitleSize(0.04);
  h31_3_2->GetYaxis()->SetTitleSize(0.04);

  h32_2_2->SetMarkerStyle(20);
  h32_2_2->SetMarkerSize(1.5);
  h32_2_2->GetYaxis()->SetTitleOffset(1.2);
  h32_2_2->GetXaxis()->SetTitleSize(0.04);
  h32_2_2->GetYaxis()->SetTitleSize(0.04);

  h32_3_2->SetMarkerStyle(20);
  h32_3_2->SetMarkerSize(1.5);
  h32_3_2->GetYaxis()->SetTitleOffset(1.2);
  h32_3_2->GetXaxis()->SetTitleSize(0.04);
  h32_3_2->GetYaxis()->SetTitleSize(0.04);

  // histo3
  h21_1_3->SetMarkerStyle(20);
  h21_1_3->SetMarkerSize(1.5);
  h21_1_3->GetYaxis()->SetTitleOffset(1.2);
  h21_1_3->GetXaxis()->SetTitleSize(0.04);
  h21_1_3->GetYaxis()->SetTitleSize(0.04);

  h21_2_3->SetMarkerStyle(20);
  h21_2_3->SetMarkerSize(1.5);
  h21_2_3->GetYaxis()->SetTitleOffset(1.2);
  h21_2_3->GetXaxis()->SetTitleSize(0.04);
  h21_2_3->GetYaxis()->SetTitleSize(0.04);

  h31_1_3->SetMarkerStyle(20);
  h31_1_3->SetMarkerSize(1.5);
  h31_1_3->GetYaxis()->SetTitleOffset(1.2);
  h31_1_3->GetXaxis()->SetTitleSize(0.04);
  h31_1_3->GetYaxis()->SetTitleSize(0.04);

  h31_3_3->SetMarkerStyle(20);
  h31_3_3->SetMarkerSize(1.5);
  h31_3_3->GetYaxis()->SetTitleOffset(1.2);
  h31_3_3->GetXaxis()->SetTitleSize(0.04);
  h31_3_3->GetYaxis()->SetTitleSize(0.04);

  h32_2_3->SetMarkerStyle(20);
  h32_2_3->SetMarkerSize(1.5);
  h32_2_3->GetYaxis()->SetTitleOffset(1.2);
  h32_2_3->GetXaxis()->SetTitleSize(0.04);
  h32_2_3->GetYaxis()->SetTitleSize(0.04);

  h32_3_3->SetMarkerStyle(20);
  h32_3_3->SetMarkerSize(1.5);
  h32_3_3->GetYaxis()->SetTitleOffset(1.2);
  h32_3_3->GetXaxis()->SetTitleSize(0.04);
  h32_3_3->GetYaxis()->SetTitleSize(0.04);

  // histo4
  h21_1_4->SetMarkerStyle(20);
  h21_1_4->SetMarkerSize(1.5);
  h21_1_4->GetYaxis()->SetTitleOffset(1.5);
  h21_1_4->GetXaxis()->SetTitleSize(0.04);
  h21_1_4->GetYaxis()->SetTitleSize(0.04);

  h21_2_4->SetMarkerStyle(20);
  h21_2_4->SetMarkerSize(1.5);
  h21_2_4->GetYaxis()->SetTitleOffset(1.5);
  h21_2_4->GetXaxis()->SetTitleSize(0.04);
  h21_2_4->GetYaxis()->SetTitleSize(0.04);

  h31_1_4->SetMarkerStyle(20);
  h31_1_4->SetMarkerSize(1.5);
  h31_1_4->GetYaxis()->SetTitleOffset(1.5);
  h31_1_4->GetXaxis()->SetTitleSize(0.04);
  h31_1_4->GetYaxis()->SetTitleSize(0.04);

  h31_3_4->SetMarkerStyle(20);
  h31_3_4->SetMarkerSize(1.5);
  h31_3_4->GetYaxis()->SetTitleOffset(1.5);
  h31_3_4->GetXaxis()->SetTitleSize(0.04);
  h31_3_4->GetYaxis()->SetTitleSize(0.04);

  h32_2_4->SetMarkerStyle(20);
  h32_2_4->SetMarkerSize(1.5);
  h32_2_4->GetYaxis()->SetTitleOffset(1.5);
  h32_2_4->GetXaxis()->SetTitleSize(0.04);
  h32_2_4->GetYaxis()->SetTitleSize(0.04);

  h32_3_4->SetMarkerStyle(20);
  h32_3_4->SetMarkerSize(1.5);
  h32_3_4->GetYaxis()->SetTitleOffset(1.5);
  h32_3_4->GetXaxis()->SetTitleSize(0.04);
  h32_3_4->GetYaxis()->SetTitleSize(0.04);

  // histo5
  h21_1_5->SetMarkerStyle(20);
  h21_1_5->SetMarkerSize(1.5);
  h21_1_5->GetYaxis()->SetTitleOffset(1.5);
  h21_1_5->GetXaxis()->SetTitleSize(0.04);
  h21_1_5->GetYaxis()->SetTitleSize(0.04);

  h21_2_5->SetMarkerStyle(20);
  h21_2_5->SetMarkerSize(1.5);
  h21_2_5->GetYaxis()->SetTitleOffset(1.5);
  h21_2_5->GetXaxis()->SetTitleSize(0.04);
  h21_2_5->GetYaxis()->SetTitleSize(0.04);

  h31_1_5->SetMarkerStyle(20);
  h31_1_5->SetMarkerSize(1.5);
  h31_1_5->GetYaxis()->SetTitleOffset(1.5);
  h31_1_5->GetXaxis()->SetTitleSize(0.04);
  h31_1_5->GetYaxis()->SetTitleSize(0.04);

  h31_3_5->SetMarkerStyle(20);
  h31_3_5->SetMarkerSize(1.5);
  h31_3_5->GetYaxis()->SetTitleOffset(1.5);
  h31_3_5->GetXaxis()->SetTitleSize(0.04);
  h31_3_5->GetYaxis()->SetTitleSize(0.04);

  h32_2_5->SetMarkerStyle(20);
  h32_2_5->SetMarkerSize(1.5);
  h32_2_5->GetYaxis()->SetTitleOffset(1.5);
  h32_2_5->GetXaxis()->SetTitleSize(0.04);
  h32_2_5->GetYaxis()->SetTitleSize(0.04);

  h32_3_5->SetMarkerStyle(20);
  h32_3_5->SetMarkerSize(1.5);
  h32_3_5->GetYaxis()->SetTitleOffset(1.5);
  h32_3_5->GetXaxis()->SetTitleSize(0.04);
  h32_3_5->GetYaxis()->SetTitleSize(0.04);

  // drawing cut_nocut on canvas
  TCanvas *c_cutDouble0 =
      new TCanvas("c_cutDouble0", "c_cutDouble0", 1000, 600);
  TCanvas *c_cutDouble1 =
      new TCanvas("c_cutDouble1", "c_cutDouble1", 1000, 600);
  TCanvas *c_cutDouble2 =
      new TCanvas("c_cutDouble2", "c_cutDouble2", 1000, 600);
  TCanvas *c_cutDouble3 =
      new TCanvas("c_cutDouble3", "c_cutDouble3", 1000, 600);
  TCanvas *c_cutDouble4 =
      new TCanvas("c_cutDouble4", "c_cutDouble4", 1000, 600);
  TCanvas *c_cutDouble5 =
      new TCanvas("c_cutDouble5", "c_cutDouble5", 1000, 600);
  TCanvas *c_cutDouble6 =
      new TCanvas("c_cutDouble6", "c_cutDouble6", 1000, 600);
  TCanvas *c_cutDouble7 =
      new TCanvas("c_cutDouble7", "c_cutDouble7", 1000, 600);
  TCanvas *c_cutDouble8 =
      new TCanvas("c_cutDouble8", "c_cutDouble8", 1000, 600);
  TCanvas *c_cutDouble9 =
      new TCanvas("c_cutDouble9", "c_cutDouble9", 1000, 600);
  TCanvas *c_cutDouble10 =
      new TCanvas("c_cutDouble10", "c_cutDouble10", 1000, 600);
  TCanvas *c_cutDouble11 =
      new TCanvas("c_cutDouble11", "c_cutDouble11", 1000, 600);
  TCanvas *c_cutDouble12 =
      new TCanvas("c_cutDouble12", "c_cutDouble12", 1000, 600);
  TCanvas *c_cutDouble13 =
      new TCanvas("c_cutDouble13", "c_cutDouble13", 1000, 600);
  TCanvas *c_cutDouble14 =
      new TCanvas("c_cutDouble14", "c_cutDouble14", 1000, 600);
  TCanvas *c_cutDouble15 =
      new TCanvas("c_cutDouble15", "c_cutDouble15", 1000, 600);
  TCanvas *c_cutDouble16 =
      new TCanvas("c_cutDouble16", "c_cutDouble16", 1000, 600);
  TCanvas *c_cutDouble17 =
      new TCanvas("c_cutDouble17", "c_cutDouble17", 1000, 600);

  // divide canvas
  c_cutDouble0->Divide(2, 1);
  c_cutDouble1->Divide(2, 1);
  c_cutDouble2->Divide(2, 1);
  c_cutDouble3->Divide(2, 1);
  c_cutDouble4->Divide(2, 1);
  c_cutDouble5->Divide(2, 1);
  c_cutDouble6->Divide(2, 1);
  c_cutDouble7->Divide(2, 1);
  c_cutDouble8->Divide(2, 1);
  c_cutDouble9->Divide(2, 1);
  c_cutDouble10->Divide(2, 1);
  c_cutDouble11->Divide(2, 1);
  c_cutDouble12->Divide(2, 1);
  c_cutDouble13->Divide(2, 1);
  c_cutDouble14->Divide(2, 1);
  c_cutDouble15->Divide(2, 1);
  c_cutDouble16->Divide(2, 1);
  c_cutDouble17->Divide(2, 1);

  // histo0
  c_cutDouble0->cd(1);
  h0_1->Draw();
  c_cutDouble0->cd(2);
  h21_1_0->Draw();
  h31_1_0->Draw("same");
  c_cutDouble1->cd(1);
  h0_2->Draw();
  c_cutDouble1->cd(2);
  h21_2_0->Draw();
  h32_2_0->Draw("same");
  c_cutDouble2->cd(1);
  h0_3->Draw();
  c_cutDouble2->cd(2);
  h31_3_0->Draw();
  h32_3_0->Draw("same");

  // histo1
  c_cutDouble3->cd(1);
  h1_1->Draw();
  c_cutDouble3->cd(2);
  h21_1_1->Draw();
  h31_1_1->Draw("same");
  c_cutDouble4->cd(1);
  h1_2->Draw();
  c_cutDouble4->cd(2);
  h21_2_1->Draw();
  h32_2_1->Draw("same");
  c_cutDouble5->cd(1);
  h1_3->Draw();
  c_cutDouble5->cd(2);
  h31_3_1->Draw();
  h32_3_1->Draw("same");

  // histo2
  c_cutDouble6->cd(1);
  h2_1->Draw();
  c_cutDouble6->cd(2);
  h21_1_2->Draw();
  h31_1_2->Draw("same");
  c_cutDouble7->cd(1);
  h2_2->Draw();
  c_cutDouble7->cd(2);
  h21_2_2->Draw();
  h32_2_2->Draw("same");
  c_cutDouble8->cd(1);
  h2_3->Draw();
  c_cutDouble8->cd(2);
  h31_3_2->Draw();
  h32_3_2->Draw("same");

  // histo3
  c_cutDouble9->cd(1);
  h3_1->Draw();
  c_cutDouble9->cd(2);
  h21_1_3->Draw();
  h31_1_3->Draw("same");
  c_cutDouble10->cd(1);
  h3_2->Draw();
  c_cutDouble10->cd(2);
  h21_2_3->Draw();
  h32_2_3->Draw("same");
  c_cutDouble11->cd(1);
  h3_3->Draw();
  c_cutDouble11->cd(2);
  h31_3_3->Draw();
  h32_3_3->Draw("same");

  // histo4
  c_cutDouble12->cd(1);
  h4_1->Draw();
  c_cutDouble12->cd(2);
  h21_1_4->Draw();
  h31_1_4->Draw("same");
  c_cutDouble13->cd(1);
  h4_2->Draw();
  c_cutDouble13->cd(2);
  h21_2_4->Draw();
  h32_2_4->Draw("same");
  c_cutDouble14->cd(1);
  h4_3->Draw();
  c_cutDouble14->cd(2);
  h31_3_4->Draw();
  h32_3_4->Draw("same");

  // histo5
  c_cutDouble15->cd(1);
  h5_1->Draw();
  c_cutDouble15->cd(2);
  h21_1_5->Draw();
  h31_1_5->Draw("same");
  c_cutDouble16->cd(1);
  h5_2->Draw();
  c_cutDouble16->cd(2);
  h21_2_5->Draw();
  h32_2_5->Draw("same");
  c_cutDouble17->cd(1);
  h5_3->Draw();
  c_cutDouble17->cd(2);
  h31_3_5->Draw();
  h32_3_5->Draw("same");

  // fit functions
  // histo0
  TF1 *f_cut0_1 = new TF1("f_cut0_1", "gaus", 0., 8.);
  TF1 *f_cut0_2 = new TF1("f_cut0_2", "gaus", 0., 8.);
  TF1 *f_cut0_3 = new TF1("f_cut0_3", "gaus", 0., 8.);

  // histo1
  TF1 *f_cut1_1 = new TF1("f_cut1_1", "gaus", 0., 9.);
  TF1 *f_cut1_2 = new TF1("f_cut1_2", "gaus", 0., 9.);

  // histo2
  TF1 *f_cut2_1 = new TF1("f_cut2_1", "gaus", 2., 18.);
  TF1 *f_cut2_2 = new TF1("f_cut2_2", "gaus", 2., 18.);
  TF1 *f_cut2_3 = new TF1("f_cut2_3", "gaus", 2., 18.);

  // histo3
  TF1 *f_cut3_1 = new TF1("f_cut3_1", "gaus", 4., 20.);
  TF1 *f_cut3_2 = new TF1("f_cut3_2", "gaus", 4., 20.);
  TF1 *f_cut3_3 = new TF1("f_cut3_3", "gaus", 4., 20.);

  // histo4
  TF1 *f_cut4_1 = new TF1("f_cut4_1", "gaus", 4., 24.);
  TF1 *f_cut4_2 = new TF1("f_cut4_2", "gaus", 4., 24.);

  // histo5
  TF1 *f_cut5_tot = new TF1("f_cut5_tot", "gaus", 8., 18.);

  // definition of vector for TGraphs
  std::vector<Double_t> v_black_a1_err{};
  std::vector<Double_t> v_black_a2_err{};
  std::vector<Double_t> v_black_a3_err{};
  std::vector<Double_t> v_black_a1_mean{};
  std::vector<Double_t> v_black_a2_mean{};
  std::vector<Double_t> v_black_a3_mean{};

  std::vector<Double_t> v_blue_a1_err{};
  std::vector<Double_t> v_blue_a2_err{};
  std::vector<Double_t> v_blue_a3_err{};
  std::vector<Double_t> v_blue_a1_mean{};
  std::vector<Double_t> v_blue_a2_mean{};
  std::vector<Double_t> v_blue_a3_mean{};

  // fit functions cosmetics
  // histo0
  f_cut0_1->SetLineColor(kRed);
  f_cut0_1->SetLineWidth(3);
  f_cut0_1->SetLineStyle(2);

  f_cut0_2->SetLineColor(kRed);
  f_cut0_2->SetLineWidth(3);
  f_cut0_2->SetLineStyle(2);

  f_cut0_3->SetLineColor(kRed);
  f_cut0_3->SetLineWidth(3);
  f_cut0_3->SetLineStyle(2);

  // histo1
  f_cut1_1->SetLineColor(kRed);
  f_cut1_1->SetLineWidth(3);
  f_cut1_1->SetLineStyle(2);

  f_cut1_2->SetLineColor(kRed);
  f_cut1_2->SetLineWidth(3);
  f_cut1_2->SetLineStyle(2);

  // histo2
  f_cut2_1->SetLineColor(kRed);
  f_cut2_1->SetLineWidth(3);
  f_cut2_1->SetLineStyle(2);

  f_cut2_2->SetLineColor(kRed);
  f_cut2_2->SetLineWidth(3);
  f_cut2_2->SetLineStyle(2);

  f_cut2_3->SetLineColor(kRed);
  f_cut2_3->SetLineWidth(3);
  f_cut2_3->SetLineStyle(2);

  // histo3
  f_cut3_1->SetLineColor(kRed);
  f_cut3_1->SetLineWidth(3);
  f_cut3_1->SetLineStyle(2);

  f_cut3_2->SetLineColor(kRed);
  f_cut3_2->SetLineWidth(3);
  f_cut3_2->SetLineStyle(2);

  f_cut3_3->SetLineColor(kRed);
  f_cut3_3->SetLineWidth(3);
  f_cut3_3->SetLineStyle(2);

  // histo4
  f_cut4_1->SetLineColor(kRed);
  f_cut4_1->SetLineWidth(3);
  f_cut4_1->SetLineStyle(2);

  f_cut4_2->SetLineColor(kRed);
  f_cut4_2->SetLineWidth(3);
  f_cut4_2->SetLineStyle(2);

  // histo5
  f_cut5_tot->SetLineColor(kOrange);
  f_cut5_tot->SetLineWidth(3);
  f_cut5_tot->SetLineStyle(2);

  // setting parameters
  // histo0
  f_cut0_1->SetParameter(1, 1);
  f_cut0_2->SetParameter(1, 2);
  f_cut0_3->SetParameter(1, 3);

  f_cut0_1->SetParameter(2, 0.5);
  f_cut0_2->SetParameter(2, 0.5);
  f_cut0_3->SetParameter(2, 0.5);

  // histo1
  f_cut1_1->SetParameter(1, 3);
  f_cut1_2->SetParameter(1, 4);

  f_cut1_1->SetParameter(2, 0.5);
  f_cut1_2->SetParameter(2, 0.5);

  // histo2
  f_cut2_1->SetParameter(1, 6);
  f_cut2_2->SetParameter(1, 7);
  f_cut2_3->SetParameter(1, 8);

  f_cut2_1->SetParameter(2, 1);
  f_cut2_2->SetParameter(2, 1);
  f_cut2_3->SetParameter(2, 1);

  // histo3
  f_cut3_1->SetParameter(1, 7);
  f_cut3_2->SetParameter(1, 9);
  f_cut3_3->SetParameter(1, 10);

  f_cut3_1->SetParameter(2, 0.5);
  f_cut3_2->SetParameter(2, 0.5);
  f_cut3_3->SetParameter(2, 0.5);

  // histo4
  f_cut4_1->SetParameter(1, 10);
  f_cut4_2->SetParameter(1, 11);

  f_cut4_1->SetParameter(2, 0.5);
  f_cut4_2->SetParameter(2, 0.5);

  // histo5
  f_cut5_tot->SetParameter(1, 12);
  f_cut5_tot->SetParameter(2, 1.);

  // fitting on black histos
  // histo0
  h31_1_0->Fit(f_cut0_1, "", "", 0.5, 1.5);
  v_black_a1_err.push_back(100. * (f_cut0_1->GetParameter(2)) /
                           (f_cut0_1->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut0_1->GetParameter(1));

  h31_1_0->Fit(f_cut0_2, "+", "", 1.5, 2.5);
  v_black_a1_err.push_back(100. * (f_cut0_2->GetParameter(2)) /
                           (f_cut0_2->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut0_2->GetParameter(1));

  h31_1_0->Fit(f_cut0_3, "+", "", 2.5, 3.5);
  v_black_a1_err.push_back(100. * (f_cut0_3->GetParameter(2)) /
                           (f_cut0_3->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut0_3->GetParameter(1));

  h32_2_0->Fit(f_cut0_1, "", "", 0.5, 1.5);
  v_black_a2_err.push_back(100. * (f_cut0_1->GetParameter(2)) /
                           (f_cut0_1->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut0_1->GetParameter(1));

  h32_2_0->Fit(f_cut0_2, "+", "", 1.5, 2.5);
  v_black_a2_err.push_back(100. * (f_cut0_2->GetParameter(2)) /
                           (f_cut0_2->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut0_2->GetParameter(1));

  h32_2_0->Fit(f_cut0_3, "+", "", 2.5, 3.5);
  v_black_a2_err.push_back(100. * (f_cut0_3->GetParameter(2)) /
                           (f_cut0_3->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut0_3->GetParameter(1));

  h32_3_0->Fit(f_cut0_1, "", "", 0.5, 1.5);
  v_black_a3_err.push_back(100. * (f_cut0_1->GetParameter(2)) /
                           (f_cut0_1->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut0_1->GetParameter(1));

  h32_3_0->Fit(f_cut0_2, "+", "", 1.5, 2.5);
  v_black_a3_err.push_back(100. * (f_cut0_2->GetParameter(2)) /
                           (f_cut0_2->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut0_2->GetParameter(1));

  h32_3_0->Fit(f_cut0_3, "+", "", 2.5, 3.5);
  v_black_a3_err.push_back(100. * (f_cut0_3->GetParameter(2)) /
                           (f_cut0_3->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut0_3->GetParameter(1));

  // histo1
  h31_1_1->Fit(f_cut1_1, "", "", 2.5, 3.6);
  v_black_a1_err.push_back(100. * (f_cut1_1->GetParameter(2)) /
                           (f_cut1_1->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut1_1->GetParameter(1));

  h31_1_1->Fit(f_cut1_2, "+", "", 3.5, 5);
  v_black_a1_err.push_back(100. * (f_cut1_2->GetParameter(2)) /
                           (f_cut1_2->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut1_2->GetParameter(1));

  h32_2_1->Fit(f_cut1_1, "", "", 2.5, 3.3);
  v_black_a2_err.push_back(100. * (f_cut1_1->GetParameter(2)) /
                           (f_cut1_1->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut1_1->GetParameter(1));

  h32_2_1->Fit(f_cut1_2, "+", "", 3.3, 5.);
  v_black_a2_err.push_back(100. * (f_cut1_2->GetParameter(2)) /
                           (f_cut1_2->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut1_2->GetParameter(1));

  h32_3_1->Fit(f_cut1_1, "", "", 2., 3.5);
  v_black_a3_err.push_back(100. * (f_cut1_1->GetParameter(2)) /
                           (f_cut1_1->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut1_1->GetParameter(1));

  h32_3_1->Fit(f_cut1_2, "+", "", 3.3, 5.);
  v_black_a3_err.push_back(100. * (f_cut1_2->GetParameter(2)) /
                           (f_cut1_2->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut1_2->GetParameter(1));

  // histo2
  h31_1_2->Fit(f_cut2_1, "", "", 5.5, 6.7);
  v_black_a1_err.push_back(100. * (f_cut2_1->GetParameter(2)) /
                           (f_cut2_1->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut2_1->GetParameter(1));

  h31_1_2->Fit(f_cut2_2, "+", "", 6.5, 7.7);
  v_black_a1_err.push_back(100. * (f_cut2_2->GetParameter(2)) /
                           (f_cut2_2->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut2_2->GetParameter(1));

  h31_1_2->Fit(f_cut2_3, "+", "", 7.6, 9.);

  h32_2_2->Fit(f_cut2_1, "", "", 5.5, 6.5);
  v_black_a2_err.push_back(100. * (f_cut2_1->GetParameter(2)) /
                           (f_cut2_1->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut2_1->GetParameter(1));

  h32_2_2->Fit(f_cut2_2, "+", "", 6.5, 7.5);
  v_black_a2_err.push_back(100. * (f_cut2_2->GetParameter(2)) /
                           (f_cut2_2->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut2_2->GetParameter(1));

  h32_2_2->Fit(f_cut2_3, "+", "", 7.5, 9.);

  h32_3_2->Fit(f_cut2_1, "", "", 4.5, 6.5);
  v_black_a3_err.push_back(100. * (f_cut2_1->GetParameter(2)) /
                           (f_cut2_1->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut2_1->GetParameter(1));

  h32_3_2->Fit(f_cut2_2, "+", "", 6.4, 7.5);
  v_black_a3_err.push_back(100. * (f_cut2_2->GetParameter(2)) /
                           (f_cut2_2->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut2_2->GetParameter(1));

  h32_3_2->Fit(f_cut2_3, "+", "", 7.4, 9.);

  // histo3
  //   h31_1_3->Fit(f_cut3_1, "", "", 6.5, 8.5);
  //   v_black_a1_err.push_back(100. * (f_cut3_1->GetParameter(2)) /
  //                            (f_cut3_1->GetParameter(1)));
  //   v_black_a1_mean.push_back(f_cut3_1->GetParameter(1));

  //   h31_1_3->Fit(f_cut3_2, "+", "", 8.5, 9.8);
  //   v_black_a1_err.push_back(100. * (f_cut3_2->GetParameter(2)) /
  //                            (f_cut3_2->GetParameter(1)));
  //   v_black_a1_mean.push_back(f_cut3_2->GetParameter(1));

  //   h31_1_3->Fit(f_cut3_3, "+", "", 9.8, 11.5);

  //   h32_2_3->Fit(f_cut3_1, "", "", 6.5, 8);
  //   v_black_a2_err.push_back(100. * (f_cut3_1->GetParameter(2)) /
  //                            (f_cut3_1->GetParameter(1)));
  //   v_black_a2_mean.push_back(f_cut3_1->GetParameter(1));

  //   h32_2_3->Fit(f_cut3_2, "+", "", 8., 9.4);
  //   v_black_a2_err.push_back(100. * (f_cut3_2->GetParameter(2)) /
  //                            (f_cut3_2->GetParameter(1)));
  //   v_black_a2_mean.push_back(f_cut3_2->GetParameter(1));

  //   h32_2_3->Fit(f_cut3_3, "+", "", 9.4, 11.);

  //   h32_3_3->Fit(f_cut3_1, "", "", 6., 8.4);
  //   v_black_a3_err.push_back(100. * (f_cut3_1->GetParameter(2)) /
  //                            (f_cut3_1->GetParameter(1)));
  //   v_black_a3_mean.push_back(f_cut3_1->GetParameter(1));

  //   h32_3_3->Fit(f_cut3_2, "+", "", 8.2, 10.);
  //   v_black_a3_err.push_back(100. * (f_cut3_2->GetParameter(2)) /
  //                            (f_cut3_2->GetParameter(1)));
  //   v_black_a3_mean.push_back(f_cut3_2->GetParameter(1));

  //   h32_3_3->Fit(f_cut3_3, "+", "", 9.4, 12.);

  // histo4
  h31_1_4->Fit(f_cut4_1, "", "", 8., 11.);
  v_black_a1_err.push_back(100. * (f_cut4_1->GetParameter(2)) /
                           (f_cut4_1->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut4_1->GetParameter(1));

  h31_1_4->Fit(f_cut4_2, "+", "", 10.7, 13.5);

  h32_2_4->Fit(f_cut4_1, "", "", 8., 10.5);
  v_black_a2_err.push_back(100. * (f_cut4_1->GetParameter(2)) /
                           (f_cut4_1->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut4_1->GetParameter(1));

  h32_2_4->Fit(f_cut4_2, "+", "", 10.4, 12.);

  h32_3_4->Fit(f_cut4_1, "", "", 8., 10.5);
  v_black_a3_err.push_back(100. * (f_cut4_1->GetParameter(2)) /
                           (f_cut4_1->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut4_1->GetParameter(1));

  h32_3_4->Fit(f_cut4_2, "+", "", 10.2, 14.);

  // histo5
  h31_1_5->Fit(f_cut5_tot, "", "", 8., 16);
  v_black_a1_err.push_back(100. * (f_cut5_tot->GetParameter(2)) /
                           (f_cut5_tot->GetParameter(1)));
  v_black_a1_mean.push_back(f_cut5_tot->GetParameter(1));

  h32_2_5->Fit(f_cut5_tot, "", "", 8., 16);
  v_black_a2_err.push_back(100. * (f_cut5_tot->GetParameter(2)) /
                           (f_cut5_tot->GetParameter(1)));
  v_black_a2_mean.push_back(f_cut5_tot->GetParameter(1));

  h32_3_5->Fit(f_cut5_tot, "", "", 8., 18);
  v_black_a3_err.push_back(100. * (f_cut5_tot->GetParameter(2)) /
                           (f_cut5_tot->GetParameter(1)));
  v_black_a3_mean.push_back(f_cut5_tot->GetParameter(1));

  // fitting on blue histos
  // changing color fit function
  f_cut0_1->SetLineColor(kOrange - 3);
  f_cut0_2->SetLineColor(kOrange - 3);
  f_cut0_3->SetLineColor(kOrange - 3);
  f_cut1_1->SetLineColor(kOrange - 3);
  f_cut1_2->SetLineColor(kOrange - 3);
  f_cut2_1->SetLineColor(kOrange - 3);
  f_cut2_2->SetLineColor(kOrange - 3);
  f_cut2_3->SetLineColor(kOrange - 3);
  f_cut3_1->SetLineColor(kOrange - 3);
  f_cut3_2->SetLineColor(kOrange - 3);
  f_cut3_3->SetLineColor(kOrange - 3);
  f_cut4_1->SetLineColor(kOrange - 3);
  f_cut4_2->SetLineColor(kOrange - 3);
  f_cut5_tot->SetLineColor(kOrange - 3);

  // histo0
  h21_1_0->Fit(f_cut0_1, "", "", 0.5, 1.5);
  v_blue_a1_err.push_back(100. * (f_cut0_1->GetParameter(2)) /
                          (f_cut0_1->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut0_1->GetParameter(1));
  h21_1_0->Fit(f_cut0_2, "+", "", 1.5, 2.5);
  v_blue_a1_err.push_back(100. * (f_cut0_2->GetParameter(2)) /
                          (f_cut0_2->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut0_2->GetParameter(1));
  h21_1_0->Fit(f_cut0_3, "+", "", 2.5, 3.5);
  v_blue_a1_err.push_back(100. * (f_cut0_3->GetParameter(2)) /
                          (f_cut0_3->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut0_3->GetParameter(1));

  h21_2_0->Fit(f_cut0_1, "", "", 0.5, 1.5);
  v_blue_a2_err.push_back(100. * (f_cut0_1->GetParameter(2)) /
                          (f_cut0_1->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut0_1->GetParameter(1));
  h21_2_0->Fit(f_cut0_2, "+", "", 1.5, 2.5);
  v_blue_a2_err.push_back(100. * (f_cut0_2->GetParameter(2)) /
                          (f_cut0_2->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut0_2->GetParameter(1));
  h21_2_0->Fit(f_cut0_3, "+", "", 2.5, 3.5);
  v_blue_a2_err.push_back(100. * (f_cut0_3->GetParameter(2)) /
                          (f_cut0_3->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut0_3->GetParameter(1));

  h31_3_0->Fit(f_cut0_1, "", "", 0.5, 1.5);
  v_blue_a3_err.push_back(100. * (f_cut0_1->GetParameter(2)) /
                          (f_cut0_1->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut0_1->GetParameter(1));
  h31_3_0->Fit(f_cut0_2, "+", "", 1.5, 2.5);
  v_blue_a3_err.push_back(100. * (f_cut0_2->GetParameter(2)) /
                          (f_cut0_2->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut0_2->GetParameter(1));
  h31_3_0->Fit(f_cut0_3, "+", "", 2.5, 3.5);
  v_blue_a3_err.push_back(100. * (f_cut0_3->GetParameter(2)) /
                          (f_cut0_3->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut0_3->GetParameter(1));

  // histo1
  h21_1_1->Fit(f_cut1_1, "", "", 2.5, 3.6);
  v_blue_a1_err.push_back(100. * (f_cut1_1->GetParameter(2)) /
                          (f_cut1_1->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut1_1->GetParameter(1));
  h21_1_1->Fit(f_cut1_2, "+", "", 3.5, 5);
  v_blue_a1_err.push_back(100. * (f_cut1_2->GetParameter(2)) /
                          (f_cut1_2->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut1_2->GetParameter(1));

  h21_2_1->Fit(f_cut1_1, "", "", 2.5, 3.3);
  v_blue_a2_err.push_back(100. * (f_cut1_1->GetParameter(2)) /
                          (f_cut1_1->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut1_1->GetParameter(1));
  h21_2_1->Fit(f_cut1_2, "+", "", 3.3, 5.);
  v_blue_a2_err.push_back(100. * (f_cut1_2->GetParameter(2)) /
                          (f_cut1_2->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut1_2->GetParameter(1));

  h31_3_1->Fit(f_cut1_1, "", "", 2., 3.5);
  v_blue_a3_err.push_back(100. * (f_cut1_1->GetParameter(2)) /
                          (f_cut1_1->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut1_1->GetParameter(1));
  h31_3_1->Fit(f_cut1_2, "+", "", 3.3, 5.);
  v_blue_a3_err.push_back(100. * (f_cut1_2->GetParameter(2)) /
                          (f_cut1_2->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut1_2->GetParameter(1));

  // histo2
  h21_1_2->Fit(f_cut2_1, "", "", 5.5, 6.7);
  v_blue_a1_err.push_back(100. * (f_cut2_1->GetParameter(2)) /
                          (f_cut2_1->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut2_1->GetParameter(1));

  h21_1_2->Fit(f_cut2_2, "+", "", 6.5, 7.7);
  v_blue_a1_err.push_back(100. * (f_cut2_2->GetParameter(2)) /
                          (f_cut2_2->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut2_2->GetParameter(1));

  h21_1_2->Fit(f_cut2_3, "+", "", 7.6, 9.);

  h21_2_2->Fit(f_cut2_1, "", "", 5.5, 6.5);
  v_blue_a2_err.push_back(100. * (f_cut2_1->GetParameter(2)) /
                          (f_cut2_1->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut2_1->GetParameter(1));

  h21_2_2->Fit(f_cut2_2, "+", "", 6.5, 7.5);
  v_blue_a2_err.push_back(100. * (f_cut2_2->GetParameter(2)) /
                          (f_cut2_2->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut2_2->GetParameter(1));

  h21_2_2->Fit(f_cut2_3, "+", "", 7.5, 9.);

  h31_3_2->Fit(f_cut2_1, "", "", 4.5, 6.5);
  v_blue_a3_err.push_back(100. * (f_cut2_1->GetParameter(2)) /
                          (f_cut2_1->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut2_1->GetParameter(1));

  h31_3_2->Fit(f_cut2_2, "+", "", 6.4, 7.5);
  v_blue_a3_err.push_back(100. * (f_cut2_2->GetParameter(2)) /
                          (f_cut2_2->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut2_2->GetParameter(1));

  h31_3_2->Fit(f_cut2_3, "+", "", 7.4, 9.);

  // histo3
  //   h21_1_3->Fit(f_cut3_1, "", "", 6.5, 8.5);
  //   v_blue_a1_err.push_back(100. * (f_cut3_1->GetParameter(2)) /
  //                           (f_cut3_1->GetParameter(1)));
  //   v_blue_a1_mean.push_back(f_cut3_1->GetParameter(1));

  //   h21_1_3->Fit(f_cut3_2, "+", "", 8.5, 9.8);
  //   v_blue_a1_err.push_back(100. * (f_cut3_2->GetParameter(2)) /
  //                           (f_cut3_2->GetParameter(1)));
  //   v_blue_a1_mean.push_back(f_cut3_2->GetParameter(1));

  //   h21_1_3->Fit(f_cut3_3, "+", "", 9.8, 11.5);

  //   h21_2_3->Fit(f_cut3_1, "", "", 6.5, 8);
  //   v_blue_a2_err.push_back(100. * (f_cut3_1->GetParameter(2)) /
  //                           (f_cut3_1->GetParameter(1)));
  //   v_blue_a2_mean.push_back(f_cut3_1->GetParameter(1));

  //   h21_2_3->Fit(f_cut3_2, "+", "", 8., 9.4);
  //   v_blue_a2_err.push_back(100. * (f_cut3_2->GetParameter(2)) /
  //                           (f_cut3_2->GetParameter(1)));
  //   v_blue_a2_mean.push_back(f_cut3_2->GetParameter(1));

  //   h21_2_3->Fit(f_cut3_3, "+", "", 9.4, 11.);

  //   h31_3_3->Fit(f_cut3_1, "", "", 6., 8.4);
  //   v_blue_a3_err.push_back(100. * (f_cut3_1->GetParameter(2)) /
  //                           (f_cut3_1->GetParameter(1)));
  //   v_blue_a3_mean.push_back(f_cut3_1->GetParameter(1));

  //   h31_3_3->Fit(f_cut3_2, "+", "", 8.2, 10.);
  //   v_blue_a3_err.push_back(100. * (f_cut3_2->GetParameter(2)) /
  //                           (f_cut3_2->GetParameter(1)));
  //   v_blue_a3_mean.push_back(f_cut3_2->GetParameter(1));

  //   h31_3_3->Fit(f_cut3_3, "+", "", 9.4, 12.);

  // histo4
  h21_1_4->Fit(f_cut4_1, "", "", 8., 11.);
  v_blue_a1_err.push_back(100. * (f_cut4_1->GetParameter(2)) /
                          (f_cut4_1->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut4_1->GetParameter(1));

  h21_1_4->Fit(f_cut4_2, "+", "", 10.7, 13.5);

  h21_2_4->Fit(f_cut4_1, "", "", 8., 10.5);
  v_blue_a2_err.push_back(100. * (f_cut4_1->GetParameter(2)) /
                          (f_cut4_1->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut4_1->GetParameter(1));

  h21_2_4->Fit(f_cut4_2, "+", "", 10.4, 12.);

  h31_3_4->Fit(f_cut4_1, "", "", 8., 10.5);
  v_blue_a3_err.push_back(100. * (f_cut4_1->GetParameter(2)) /
                          (f_cut4_1->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut4_1->GetParameter(1));

  h31_3_4->Fit(f_cut4_2, "+", "", 10.2, 14.);

  // histo5
  h21_1_5->Fit(f_cut5_tot, "", "", 8., 16);
  v_blue_a1_err.push_back(100. * (f_cut5_tot->GetParameter(2)) /
                          (f_cut5_tot->GetParameter(1)));
  v_blue_a1_mean.push_back(f_cut5_tot->GetParameter(1));

  h21_2_5->Fit(f_cut5_tot, "", "", 8., 16);
  v_blue_a2_err.push_back(100. * (f_cut5_tot->GetParameter(2)) /
                          (f_cut5_tot->GetParameter(1)));
  v_blue_a2_mean.push_back(f_cut5_tot->GetParameter(1));

  h31_3_5->Fit(f_cut5_tot, "", "", 8., 18);
  v_blue_a3_err.push_back(100. * (f_cut5_tot->GetParameter(2)) /
                          (f_cut5_tot->GetParameter(1)));
  v_blue_a3_mean.push_back(f_cut5_tot->GetParameter(1));

  // creating TGraph and cosmetics
  TGraph *a1_black = new TGraph((int)v_black_a1_mean.size(),
                                &v_black_a1_mean[0], &v_black_a1_err[0]);
  TGraph *a2_black = new TGraph((int)v_black_a2_mean.size(),
                                &v_black_a2_mean[0], &v_black_a2_err[0]);
  TGraph *a3_black = new TGraph((int)v_black_a3_mean.size(),
                                &v_black_a3_mean[0], &v_black_a3_err[0]);

  TGraph *a1_blue = new TGraph((int)v_blue_a1_mean.size(), &v_blue_a1_mean[0],
                               &v_blue_a1_err[0]);
  TGraph *a2_blue = new TGraph((int)v_blue_a2_mean.size(), &v_blue_a2_mean[0],
                               &v_blue_a2_err[0]);
  TGraph *a3_blue = new TGraph((int)v_blue_a3_mean.size(), &v_blue_a3_mean[0],
                               &v_blue_a3_err[0]);

  // label points in graphs
  TLatex *latex1_1 =
      new TLatex(a1_black->GetX()[0], a1_black->GetY()[0], "  {}^{1}_{1}H");
  a1_black->GetListOfFunctions()->Add(latex1_1);
  latex1_1->SetTextSize(0.05);
  latex1_1->SetTextAlign(12);

  TLatex *latex2_1 =
      new TLatex(a1_black->GetX()[1], a1_black->GetY()[1], "  {}^{2}_{1}H");
  a1_black->GetListOfFunctions()->Add(latex2_1);
  latex2_1->SetTextSize(0.05);
  latex1_1->SetTextAlign(12);

  TLatex *latex3_1 =
      new TLatex(a1_black->GetX()[2], a1_black->GetY()[2], "  {}^{3}_{1}H");
  a1_black->GetListOfFunctions()->Add(latex3_1);
  latex3_1->SetTextSize(0.05);
  latex1_1->SetTextAlign(12);

  // defining multigraph
  TMultiGraph *black = new TMultiGraph();
  black->Add(a1_black);
  black->Add(a2_black);
  black->Add(a3_black);

  TMultiGraph *blue = new TMultiGraph();
  blue->Add(a1_blue);
  blue->Add(a2_blue);
  blue->Add(a3_blue);

  // cosmetics
  a1_black->SetMarkerColor(kBlue);
  a1_black->SetMarkerStyle(20);
  a1_black->SetMarkerSize(1.3);
  //   a1_black->SetLineWidth(2);

  a2_black->SetMarkerColor(kGreen);
  a2_black->SetMarkerStyle(20);
  a2_black->SetMarkerSize(1.3);

  a3_black->SetMarkerColor(kOrange - 3);
  a3_black->SetMarkerStyle(20);
  a3_black->SetMarkerSize(1.3);

  a1_blue->SetMarkerColor(kBlue);
  a1_blue->SetMarkerStyle(20);
  a1_blue->SetMarkerSize(1.3);

  a2_blue->SetMarkerColor(kGreen);
  a2_blue->SetMarkerStyle(20);
  a2_blue->SetMarkerSize(1.3);

  a3_blue->SetMarkerColor(kOrange - 3);
  a3_blue->SetMarkerStyle(20);
  a3_blue->SetMarkerSize(1.3);

  black->SetTitle("Black result; Mean; \u0025 error");
  blue->SetTitle("Blue result; Mean; \u0025 error");

  // canvas for multigraph
  TCanvas *c_multigr = new TCanvas("c_multigr", "c_multigr", 1000, 600);
  c_multigr->Divide(1, 2);

  // drawing on canvas and cosmetics
  // histo0
  h21_1_0->SetLineColor(kBlue);
  h21_1_0->SetLineWidth(2);
  h31_1_0->SetLineColor(kBlack);
  h31_1_0->SetLineWidth(2);
  c_cut0->cd(1);
  h21_1_0->DrawCopy();
  c_cut0->cd(2);
  h31_1_0->DrawCopy();

  h21_2_0->SetLineColor(kBlue);
  h21_2_0->SetLineWidth(2);
  h32_2_0->SetLineColor(kBlack);
  h32_2_0->SetLineWidth(2);
  c_cut1->cd(1);
  h21_2_0->DrawCopy();
  c_cut1->cd(2);
  h32_2_0->DrawCopy();

  h31_3_0->SetLineColor(kBlue);
  h31_3_0->SetLineWidth(2);
  h32_3_0->SetLineColor(kBlack);
  h32_3_0->SetLineWidth(2);
  c_cut2->cd(1);
  h31_3_0->DrawCopy();
  c_cut2->cd(2);
  h32_3_0->DrawCopy();

  // histo1
  h21_1_1->SetLineColor(kBlue);
  h21_1_1->SetLineWidth(2);
  h31_1_1->SetLineColor(kBlack);
  h31_1_1->SetLineWidth(2);
  c_cut3->cd(1);
  h21_1_1->DrawCopy();
  c_cut3->cd(2);
  h31_1_1->DrawCopy();

  h21_2_1->SetLineColor(kBlue);
  h21_2_1->SetLineWidth(2);
  h32_2_1->SetLineColor(kBlack);
  h32_2_1->SetLineWidth(2);
  c_cut4->cd(1);
  h21_2_1->DrawCopy();
  c_cut4->cd(2);
  h32_2_1->DrawCopy();

  h31_3_1->SetLineColor(kBlue);
  h31_3_1->SetLineWidth(2);
  h32_3_1->SetLineColor(kBlack);
  h32_3_1->SetLineWidth(2);
  c_cut5->cd(1);
  h31_3_1->DrawCopy();
  c_cut5->cd(2);
  h32_3_1->DrawCopy();

  // histo2
  h21_1_2->SetLineColor(kBlue);
  h21_1_2->SetLineWidth(2);
  h31_1_2->SetLineColor(kBlack);
  h31_1_2->SetLineWidth(2);
  c_cut6->cd(1);
  h21_1_2->DrawCopy();
  c_cut6->cd(2);
  h31_1_2->DrawCopy();

  h21_2_2->SetLineColor(kBlue);
  h21_2_2->SetLineWidth(2);
  h32_2_2->SetLineColor(kBlack);
  h32_2_2->SetLineWidth(2);
  c_cut7->cd(1);
  h21_2_2->DrawCopy();
  c_cut7->cd(2);
  h32_2_2->DrawCopy();

  h31_3_2->SetLineColor(kBlue);
  h31_3_2->SetLineWidth(2);
  h32_3_2->SetLineColor(kBlack);
  h32_3_2->SetLineWidth(2);
  c_cut8->cd(1);
  h31_3_2->DrawCopy();
  c_cut8->cd(2);
  h32_3_2->DrawCopy();

  // histo3
  h21_1_3->SetLineColor(kBlue);
  h21_1_3->SetLineWidth(2);
  h31_1_3->SetLineColor(kBlack);
  h31_1_3->SetLineWidth(2);
  c_cut9->cd(1);
  h21_1_3->DrawCopy();
  c_cut9->cd(2);
  h31_1_3->DrawCopy();

  h21_2_3->SetLineColor(kBlue);
  h21_2_3->SetLineWidth(2);
  h32_2_3->SetLineColor(kBlack);
  h32_2_3->SetLineWidth(2);
  c_cut10->cd(1);
  h21_2_3->DrawCopy();
  c_cut10->cd(2);
  h32_2_3->DrawCopy();

  h31_3_3->SetLineColor(kBlue);
  h31_3_3->SetLineWidth(2);
  h32_3_3->SetLineColor(kBlack);
  h32_3_3->SetLineWidth(2);
  c_cut11->cd(1);
  h31_3_3->DrawCopy();
  c_cut11->cd(2);
  h32_3_3->DrawCopy();

  // histo4
  h21_1_4->SetLineColor(kBlue);
  h21_1_4->SetLineWidth(2);
  h31_1_4->SetLineColor(kBlack);
  h31_1_4->SetLineWidth(2);
  c_cut12->cd(1);
  h21_1_4->DrawCopy();
  c_cut12->cd(2);
  h31_1_4->DrawCopy();

  h21_2_4->SetLineColor(kBlue);
  h21_2_4->SetLineWidth(2);
  h32_2_4->SetLineColor(kBlack);
  h32_2_4->SetLineWidth(2);
  c_cut13->cd(1);
  h21_2_4->DrawCopy();
  c_cut13->cd(2);
  h32_2_4->DrawCopy();

  h31_3_4->SetLineColor(kBlue);
  h31_3_4->SetLineWidth(2);
  h32_3_4->SetLineColor(kBlack);
  h32_3_4->SetLineWidth(2);
  c_cut14->cd(1);
  h31_3_4->DrawCopy();
  c_cut14->cd(2);
  h32_3_4->DrawCopy();

  // histo5
  h21_1_5->SetLineColor(kBlue);
  h21_1_5->SetLineWidth(2);
  h31_1_5->SetLineColor(kBlack);
  h31_1_5->SetLineWidth(2);
  c_cut15->cd(1);
  h21_1_5->DrawCopy();
  c_cut15->cd(2);
  h31_1_5->DrawCopy();

  h21_2_5->SetLineColor(kBlue);
  h21_2_5->SetLineWidth(2);
  h32_2_5->SetLineColor(kBlack);
  h32_2_5->SetLineWidth(2);
  c_cut16->cd(1);
  h21_2_5->DrawCopy();
  c_cut16->cd(2);
  h32_2_5->DrawCopy();

  h31_3_5->SetLineColor(kBlue);
  h31_3_5->SetLineWidth(2);
  h32_3_5->SetLineColor(kBlack);
  h32_3_5->SetLineWidth(2);
  c_cut17->cd(1);
  h31_3_5->DrawCopy();
  c_cut17->cd(2);
  h32_3_5->DrawCopy();

  // define legend
  TLegend *leg1 = new TLegend(.70, .7, .9, .9, "Legenda");
  leg1->SetFillColor(0);
  leg1->AddEntry(a1_black, "A_{1} ricostruito", "P");
  leg1->AddEntry(a2_black, "A_{2} ricostruito", "P");
  leg1->AddEntry(a3_black, "A_{3} ricostruito", "P");

  // draw multigraph
  c_multigr->cd(1);
  black->Draw("AP");
  leg1->Draw("same");
  c_multigr->cd(2);
  blue->Draw("AP");

  // draw cut
  TCanvas *c_Fcut0 = new TCanvas("c_Fcut0", "c_Fcut0", 1000, 600);
  TCanvas *c_Fcut1 = new TCanvas("c_Fcut1", "c_Fcut1", 1000, 600);
  TCanvas *c_Fcut2 = new TCanvas("c_Fcut2", "c_Fcut2", 1000, 600);
  TCanvas *c_Fcut3 = new TCanvas("c_Fcut3", "c_Fcut3", 1000, 600);
  TCanvas *c_Fcut4 = new TCanvas("c_Fcut4", "c_Fcut4", 1000, 600);
  TCanvas *c_Fcut5 = new TCanvas("c_Fcut5", "c_Fcut5", 1000, 600);
  TCanvas *c_Fcut6 = new TCanvas("c_Fcut6", "c_Fcut6", 1000, 600);
  TCanvas *c_Fcut7 = new TCanvas("c_Fcut7", "c_Fcut7", 1000, 600);
  TCanvas *c_Fcut8 = new TCanvas("c_Fcut8", "c_Fcut8", 1000, 600);
  TCanvas *c_Fcut9 = new TCanvas("c_Fcut9", "c_Fcut9", 1000, 600);
  TCanvas *c_Fcut10 = new TCanvas("c_Fcut10", "c_Fcut10", 1000, 600);
  TCanvas *c_Fcut11 = new TCanvas("c_Fcut11", "c_Fcut11", 1000, 600);
  TCanvas *c_Fcut12 = new TCanvas("c_Fcut12", "c_Fcut12", 1000, 600);
  TCanvas *c_Fcut13 = new TCanvas("c_Fcut13", "c_Fcut13", 1000, 600);
  TCanvas *c_Fcut14 = new TCanvas("c_Fcut14", "c_Fcut14", 1000, 600);
  TCanvas *c_Fcut15 = new TCanvas("c_Fcut15", "c_Fcut15", 1000, 600);
  TCanvas *c_Fcut16 = new TCanvas("c_Fcut16", "c_Fcut16", 1000, 600);
  TCanvas *c_Fcut17 = new TCanvas("c_Fcut17", "c_Fcut17", 1000, 600);

  TF1 *f0_1 = new TF1("f0_1", "0.898366*x-0.0128952", 0.5, 4.);
  TF1 *f0_2 = new TF1("f0_2", "1.20125*x-0.0939499", 0.5, 4.);
  f0_1->SetLineColor(kRed);
  f0_1->SetLineWidth(3);
  f0_1->SetLineStyle(2);
  f0_2->SetLineColor(kRed);
  f0_2->SetLineWidth(3);
  f0_2->SetLineStyle(2);
  myCut0->SetLineColor(kRed);
  myCut0->SetLineWidth(3);
  myCut0->SetLineStyle(2);
  // myCut0->SetFillStyle(3944);
  c_Fcut0->cd();
  h_Acor0->Draw("colz");
  // myCut0->Draw("same");
  f0_1->Draw("same");
  f0_2->Draw("same");

  TF1 *f1_1 = new TF1("f1_1", "0.834047*x + 0.000960117", 1., 7.);
  TF1 *f1_2 = new TF1("f1_2", "1.07576*x + 0.0998292", 1., 7.);
  f1_1->SetLineColor(kRed);
  f1_1->SetLineWidth(3);
  f1_1->SetLineStyle(2);
  f1_2->SetLineColor(kRed);
  f1_2->SetLineWidth(3);
  f1_2->SetLineStyle(2);
  c_Fcut1->cd();
  h_Acor1->Draw("colz");
  f1_1->Draw("same");
  f1_2->Draw("same");
  // myCut1->Draw("same");
  myCut1->SetLineColor(kRed);
  myCut1->SetLineWidth(3);
  myCut1->SetLineStyle(2);

  TF1 *f2_1 = new TF1("f2_1", "0.938138*x - 0.173126", 3., 10.);
  TF1 *f2_2 = new TF1("f2_2", "1.03015*x + 0.106667", 3., 10.);
  f2_1->SetLineColor(kRed);
  f2_1->SetLineWidth(3);
  f2_1->SetLineStyle(2);
  f2_2->SetLineColor(kRed);
  f2_2->SetLineWidth(3);
  f2_2->SetLineStyle(2);
  c_Fcut2->cd();
  h_Acor2->Draw("colz");
  f2_1->Draw("same");
  f2_2->Draw("same");
  //   myCut2->Draw("same");
  myCut2->SetLineColor(kRed);
  myCut2->SetLineWidth(3);
  myCut2->SetLineStyle(2);

  TF1 *f3_1 = new TF1("f3_1", "0.887282*x - 0.00191072", 4.5, 11.5);
  TF1 *f3_2 = new TF1("f3_2", "1.125*x - 0.57", 4.5, 11.5);
  f3_1->SetLineColor(kRed);
  f3_1->SetLineWidth(3);
  f3_1->SetLineStyle(2);
  f3_2->SetLineColor(kRed);
  f3_2->SetLineWidth(3);
  f3_2->SetLineStyle(2);
  c_Fcut3->cd();
  h_Acor3->Draw("colz");
  f3_1->Draw("same");
  f3_2->Draw("same");
  //   myCut3->Draw("same");
  myCut3->SetLineColor(kRed);
  myCut3->SetLineWidth(3);
  myCut3->SetLineStyle(2);

  TF1 *f4_1 = new TF1("f4_1", "0.874419*x + 0.0828994", 7., 15.);
  TF1 *f4_2 = new TF1("f4_2", "1.04031*x - 0.288635", 7., 15.);
  f4_1->SetLineColor(kRed);
  f4_1->SetLineWidth(3);
  f4_1->SetLineStyle(2);
  f4_2->SetLineColor(kRed);
  f4_2->SetLineWidth(3);
  f4_2->SetLineStyle(2);
  c_Fcut4->cd();
  h_Acor4->Draw("colz");
  f4_1->Draw("same");
  f4_2->Draw("same");
  // myCut4->Draw("same");
  myCut4->SetLineColor(kRed);
  myCut4->SetLineWidth(3);
  myCut4->SetLineStyle(2);

  TF1 *f5_1 = new TF1("f5_1", "0.80605*x + 0.391506", 8.5, 15.);
  TF1 *f5_2 = new TF1("f5_2", "1.27583*x - 2.28309", 8.5, 15.);
  f5_1->SetLineColor(kRed);
  f5_1->SetLineWidth(3);
  f5_1->SetLineStyle(2);
  f5_2->SetLineColor(kRed);
  f5_2->SetLineWidth(3);
  f5_2->SetLineStyle(2);
  c_Fcut5->cd();
  h_Acor5->Draw("colz");
  f5_1->Draw("same");
  f5_2->Draw("same");
  // myCut5->Draw("same");
  myCut5->SetLineColor(kRed);
  myCut5->SetLineWidth(3);
  myCut5->SetLineStyle(2);

  TF1 *f6_1 = new TF1("f6_1", "0.929088*x - 0.206651", 0.5, 4.);
  TF1 *f6_2 = new TF1("f6_2", "1.08272*x + 0.05382", 0.5, 4.);
  f6_1->SetLineColor(kRed);
  f6_1->SetLineWidth(3);
  f6_1->SetLineStyle(2);
  f6_2->SetLineColor(kRed);
  f6_2->SetLineWidth(3);
  f6_2->SetLineStyle(2);
  c_Fcut6->cd();
  h_Acor6->Draw("colz");
  // myCut6->Draw("same");
  f6_1->Draw("same");
  f6_2->Draw("same");
  myCut6->SetLineColor(kRed);
  myCut6->SetLineWidth(3);
  myCut6->SetLineStyle(2);

  TF1 *f7_1 = new TF1("f7_1", "0.879598*x - 0.0897704", 1., 7.);
  TF1 *f7_2 = new TF1("f7_2", "0.8199*x + 1.18526", 1., 7.);
  f7_1->SetLineColor(kRed);
  f7_1->SetLineWidth(3);
  f7_1->SetLineStyle(2);
  f7_2->SetLineColor(kRed);
  f7_2->SetLineWidth(3);
  f7_2->SetLineStyle(2);
  c_Fcut7->cd();
  h_Acor7->Draw("colz");
  f7_1->Draw("same");
  f7_2->Draw("same");
  //   myCut7->Draw("same");
  myCut7->SetLineColor(kRed);
  myCut7->SetLineWidth(3);
  myCut7->SetLineStyle(2);

  TF1 *f8_1 = new TF1("f8_1", "0.857437*x + 0.378008", 3., 10.);
  TF1 *f8_2 = new TF1("f8_2", "0.985377*x + 0.35161", 3., 10.);
  f8_1->SetLineColor(kRed);
  f8_1->SetLineWidth(3);
  f8_1->SetLineStyle(2);
  f8_2->SetLineColor(kRed);
  f8_2->SetLineWidth(3);
  f8_2->SetLineStyle(2);
  c_Fcut8->cd();
  h_Acor8->Draw("colz");
  f8_1->Draw("same");
  f8_2->Draw("same");
  //   myCut8->Draw("same");
  myCut8->SetLineColor(kRed);
  myCut8->SetLineWidth(3);
  myCut8->SetLineStyle(2);

  TF1 *f9_1 = new TF1("f9_1", "0.893464*x + 0.0625748", 4.5, 11.5);
  TF1 *f9_2 = new TF1("f9_2", "0.833128*x + 2.42274", 4.5, 11.5);
  f9_1->SetLineColor(kRed);
  f9_1->SetLineWidth(3);
  f9_1->SetLineStyle(2);
  f9_2->SetLineColor(kRed);
  f9_2->SetLineWidth(3);
  f9_2->SetLineStyle(2);
  c_Fcut9->cd();
  h_Acor9->Draw("colz");
  f9_1->Draw("same");
  f9_2->Draw("same");
  //   myCut9->Draw("same");
  myCut9->SetLineColor(kRed);
  myCut9->SetLineWidth(3);
  myCut9->SetLineStyle(2);

  TF1 *f10_1 = new TF1("f10_1", "0.793858*x + 1.56332", 7., 15.);
  TF1 *f10_2 = new TF1("f10_2", "0.984752*x + 0.704394", 7., 15.);
  f10_1->SetLineColor(kRed);
  f10_1->SetLineWidth(3);
  f10_1->SetLineStyle(2);
  f10_2->SetLineColor(kRed);
  f10_2->SetLineWidth(3);
  f10_2->SetLineStyle(2);
  c_Fcut10->cd();
  h_Acor10->Draw("colz");
  f10_1->Draw("same");
  f10_2->Draw("same");
  //   myCut10->Draw("same");
  myCut10->SetLineColor(kRed);
  h_Acor10->SetLineWidth(3);
  h_Acor10->SetLineStyle(2);

  TF1 *f11_1 = new TF1("f11_1", "0.834673*x + 0.521629", 8.5, 15.);
  TF1 *f11_2 = new TF1("f11_2", "1.19328*x - 1.00575", 8.5, 15.);
  f11_1->SetLineColor(kRed);
  f11_1->SetLineWidth(3);
  f11_1->SetLineStyle(2);
  f11_2->SetLineColor(kRed);
  f11_2->SetLineWidth(3);
  f11_2->SetLineStyle(2);
  c_Fcut11->cd();
  h_Acor11->Draw("colz");
  f11_1->Draw("same");
  f11_2->Draw("same");
  //   myCut11->Draw("same");
  myCut11->SetLineColor(kRed);
  myCut11->SetLineWidth(3);
  myCut11->SetLineStyle(2);

  TF1 *f12_1 = new TF1("f12_1", "0.854911*x - 0.130298", 0.5, 4.);
  TF1 *f12_2 = new TF1("f12_2", "1.10416*x + 0.176225", 0.5, 4.);
  f12_1->SetLineColor(kRed);
  f12_1->SetLineWidth(3);
  f12_1->SetLineStyle(2);
  f12_2->SetLineColor(kRed);
  f12_2->SetLineWidth(3);
  f12_2->SetLineStyle(2);
  c_Fcut12->cd();
  h_Acor12->Draw("colz");
  f12_1->Draw("same");
  f12_2->Draw("same");
  //   myCut12->Draw("same");
  myCut12->SetLineColor(kRed);
  myCut12->SetLineWidth(3);
  myCut12->SetLineStyle(2);

  TF1 *f13_1 = new TF1("f13_1", "0.83875*x - 0.0637813", 1., 7.);
  TF1 *f13_2 = new TF1("f13_2", "1.01354*x + 0.481892", 1., 7.);
  f13_1->SetLineColor(kRed);
  f13_1->SetLineWidth(3);
  f13_1->SetLineStyle(2);
  f13_2->SetLineColor(kRed);
  f13_2->SetLineWidth(3);
  f13_2->SetLineStyle(2);
  c_Fcut13->cd();
  h_Acor13->Draw("colz");
  f13_1->Draw("same");
  f13_2->Draw("same");
  //   myCut13->Draw("same");
  myCut13->SetLineColor(kRed);
  myCut13->SetLineWidth(3);
  myCut13->SetLineStyle(2);

  TF1 *f14_1 = new TF1("f14_1", "0.951386*x - 0.451837", 3., 10.);
  TF1 *f14_2 = new TF1("f14_2", "1.09272*x + 0.0479334", 3., 10.);
  f14_1->SetLineColor(kRed);
  f14_1->SetLineWidth(3);
  f14_1->SetLineStyle(2);
  f14_2->SetLineColor(kRed);
  f14_2->SetLineWidth(3);
  f14_2->SetLineStyle(2);
  c_Fcut14->cd();
  h_Acor14->Draw("colz");
  f14_1->Draw("same");
  f14_2->Draw("same");
  //   myCut14->Draw("same");
  myCut14->SetLineColor(kRed);
  myCut14->SetLineWidth(3);
  myCut14->SetLineStyle(2);

  TF1 *f15_1 = new TF1("f15_1", "0.829295*x + 0.730928", 4.5, 11.5);
  TF1 *f15_2 = new TF1("f15_2", "1.10078*x + 0.237946", 4.5, 11.5);
  f15_1->SetLineColor(kRed);
  f15_1->SetLineWidth(3);
  f15_1->SetLineStyle(2);
  f15_2->SetLineColor(kRed);
  f15_2->SetLineWidth(3);
  f15_2->SetLineStyle(2);
  c_Fcut15->cd();
  h_Acor15->Draw("colz");
  f15_1->Draw("same");
  f15_2->Draw("same");
  //   myCut15->Draw("same");
  myCut15->SetLineColor(kRed);
  myCut15->SetLineWidth(3);
  myCut15->SetLineStyle(2);

  TF1 *f16_1 = new TF1("f16_1", "0.74629*x + 2.17232", 7., 15.);
  TF1 *f16_2 = new TF1("f16_2", "0.929428*x + 1.96892", 7., 15.);
  f16_1->SetLineColor(kRed);
  f16_1->SetLineWidth(3);
  f16_1->SetLineStyle(2);
  f16_2->SetLineColor(kRed);
  f16_2->SetLineWidth(3);
  f16_2->SetLineStyle(2);
  c_Fcut16->cd();
  h_Acor16->Draw("colz");
  f16_1->Draw("same");
  f16_2->Draw("same");
  //   myCut16->Draw("same");
  myCut16->SetLineColor(kRed);
  myCut16->SetLineWidth(3);
  myCut16->SetLineStyle(2);

  TF1 *f17_1 = new TF1("f17_1", "0.80449*x + 0.551851", 8.5, 15.);
  TF1 *f17_2 = new TF1("f17_2", "1.31545*x - 0.674489", 8.5, 15.);
  f17_1->SetLineColor(kRed);
  f17_1->SetLineWidth(3);
  f17_1->SetLineStyle(2);
  f17_2->SetLineColor(kRed);
  f17_2->SetLineWidth(3);
  f17_2->SetLineStyle(2);
  c_Fcut17->cd();
  h_Acor17->Draw("colz");
  f17_1->Draw("same");
  f17_2->Draw("same");
  //   myCut17->Draw("same");
  myCut17->SetLineColor(kRed);
  myCut17->SetLineWidth(3);
  myCut17->SetLineStyle(2);

  h_Acor0->GetXaxis()->SetRangeUser(0., 5.);
  h_Acor1->GetXaxis()->SetRangeUser(0., 9.);
  h_Acor2->GetXaxis()->SetRangeUser(2., 11.);
  h_Acor3->GetXaxis()->SetRangeUser(4., 12.);
  h_Acor4->GetXaxis()->SetRangeUser(6., 16.);
  h_Acor5->GetXaxis()->SetRangeUser(8., 16.5);
  h_Acor6->GetXaxis()->SetRangeUser(0., 5.);
  h_Acor7->GetXaxis()->SetRangeUser(0., 9.);
  h_Acor8->GetXaxis()->SetRangeUser(2., 11.);
  h_Acor9->GetXaxis()->SetRangeUser(4., 12.);
  h_Acor10->GetXaxis()->SetRangeUser(6., 16.);
  h_Acor11->GetXaxis()->SetRangeUser(8., 16.5);
  h_Acor12->GetXaxis()->SetRangeUser(0., 5.);
  h_Acor13->GetXaxis()->SetRangeUser(0., 9.);
  h_Acor14->GetXaxis()->SetRangeUser(2., 11.);
  h_Acor15->GetXaxis()->SetRangeUser(4., 12.);
  h_Acor16->GetXaxis()->SetRangeUser(6., 16.);
  h_Acor17->GetXaxis()->SetRangeUser(8., 16.5);

  h_Acor0->SetTitle("H");
  h_Acor1->SetTitle("He");
  h_Acor2->SetTitle("Li");
  h_Acor3->SetTitle("Be");
  h_Acor4->SetTitle("B");
  h_Acor5->SetTitle("C");
  h_Acor6->SetTitle("H");
  h_Acor7->SetTitle("He");
  h_Acor8->SetTitle("Li");
  h_Acor9->SetTitle("Be");
  h_Acor10->SetTitle("B");
  h_Acor11->SetTitle("C");
  h_Acor12->SetTitle("H");
  h_Acor13->SetTitle("He");
  h_Acor14->SetTitle("Li");
  h_Acor15->SetTitle("Be");
  h_Acor16->SetTitle("B");
  h_Acor17->SetTitle("C");

  // drawing histos on multicanvas
  TCanvas *c_MultiCanvas1 =
      new TCanvas("c_MultiCanvas1", "c_MultiCanvas1", 900, 1100);
  TCanvas *c_MultiCanvas2 =
      new TCanvas("c_MultiCanvas2", "c_MultiCanvas2", 900, 1100);
  TCanvas *c_MultiCanvas3 =
      new TCanvas("c_MultiCanvas3", "c_MultiCanvas3", 900, 1100);

  c_MultiCanvas1->Divide(2, 3);
  c_MultiCanvas2->Divide(2, 3);
  c_MultiCanvas3->Divide(2, 3);

  c_MultiCanvas1->cd(1);
  h_Acor0->Draw("colz");
  c_MultiCanvas2->cd(1);
  h_Acor6->Draw("colz");
  c_MultiCanvas3->cd(1);
  h_Acor12->Draw("colz");

  c_MultiCanvas1->cd(2);
  h_Acor1->Draw("colz");
  c_MultiCanvas2->cd(2);
  h_Acor7->Draw("colz");
  c_MultiCanvas3->cd(2);
  h_Acor13->Draw("colz");

  c_MultiCanvas1->cd(3);
  h_Acor2->Draw("colz");
  c_MultiCanvas2->cd(3);
  h_Acor8->Draw("colz");
  c_MultiCanvas3->cd(3);
  h_Acor14->Draw("colz");

  c_MultiCanvas1->cd(4);
  h_Acor3->Draw("colz");
  c_MultiCanvas2->cd(4);
  h_Acor9->Draw("colz");
  c_MultiCanvas3->cd(4);
  h_Acor15->Draw("colz");

  c_MultiCanvas1->cd(5);
  h_Acor4->Draw("colz");
  c_MultiCanvas2->cd(5);
  h_Acor10->Draw("colz");
  c_MultiCanvas3->cd(5);
  h_Acor16->Draw("colz");

  c_MultiCanvas1->cd(6);
  h_Acor5->Draw("colz");
  c_MultiCanvas2->cd(6);
  h_Acor11->Draw("colz");
  c_MultiCanvas3->cd(6);
  h_Acor17->Draw("colz");

  TCanvas *c_MultiCanvasCut1 =
      new TCanvas("c_MultiCanvasCut1", "c_MultiCanvasCut1", 900, 1100);
  TCanvas *c_MultiCanvasCut2 =
      new TCanvas("c_MultiCanvasCut2", "c_MultiCanvasCut2", 900, 1100);
  TCanvas *c_MultiCanvasCut3 =
      new TCanvas("c_MultiCanvasCut3", "c_MultiCanvasCut3", 900, 1100);

  c_MultiCanvasCut1->Divide(2, 3);
  c_MultiCanvasCut2->Divide(2, 3);
  c_MultiCanvasCut3->Divide(2, 3);

  TLegend *leg2 = new TLegend(.70, .8, .9, .9, "Legenda");
  leg2->SetFillColor(0);
  leg2->AddEntry(myCut0, "Taglio", "L");

  c_MultiCanvasCut1->cd(1);
  h_Acor0->Draw("colz");
  f0_1->Draw("same");
  f0_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut2->cd(1);
  h_Acor6->Draw("colz");
  f6_1->Draw("same");
  f6_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut3->cd(1);
  h_Acor12->Draw("colz");
  f12_1->Draw("same");
  f12_2->Draw("same");
  leg2->Draw("same");

  c_MultiCanvasCut1->cd(2);
  h_Acor1->Draw("colz");
  f1_1->Draw("same");
  f1_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut2->cd(2);
  h_Acor7->Draw("colz");
  f7_1->Draw("same");
  f7_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut3->cd(2);
  h_Acor13->Draw("colz");
  f13_1->Draw("same");
  f13_2->Draw("same");
  leg2->Draw("same");

  c_MultiCanvasCut1->cd(3);
  h_Acor2->Draw("colz");
  f2_1->Draw("same");
  f2_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut2->cd(3);
  h_Acor8->Draw("colz");
  f8_1->Draw("same");
  f8_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut3->cd(3);
  h_Acor14->Draw("colz");
  f14_1->Draw("same");
  f14_2->Draw("same");
  leg2->Draw("same");

  c_MultiCanvasCut1->cd(4);
  h_Acor3->Draw("colz");
  f3_1->Draw("same");
  f3_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut2->cd(4);
  h_Acor9->Draw("colz");
  f9_1->Draw("same");
  f9_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut3->cd(4);
  h_Acor15->Draw("colz");
  f15_1->Draw("same");
  f15_2->Draw("same");
  leg2->Draw("same");

  c_MultiCanvasCut1->cd(5);
  h_Acor4->Draw("colz");
  f4_1->Draw("same");
  f4_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut2->cd(5);
  h_Acor10->Draw("colz");
  f10_1->Draw("same");
  f10_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut3->cd(5);
  h_Acor16->Draw("colz");
  f16_1->Draw("same");
  f16_2->Draw("same");
  leg2->Draw("same");

  c_MultiCanvasCut1->cd(6);
  h_Acor5->Draw("colz");
  f5_1->Draw("same");
  f5_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut2->cd(6);
  h_Acor11->Draw("colz");
  f11_1->Draw("same");
  f11_2->Draw("same");
  leg2->Draw("same");
  c_MultiCanvasCut3->cd(6);
  h_Acor17->Draw("colz");
  f17_1->Draw("same");
  f17_2->Draw("same");
  leg2->Draw("same");

  // Berillium canvas
  TCanvas *c_Berillum = new TCanvas("c_Berillum", "c_Berillum", 900, 1100);
  TCanvas *c_Berillum1 = new TCanvas("c_Berillum1", "c_Berillum1", 900, 367);
  TCanvas *c_Berillum2 = new TCanvas("c_Berillum2", "c_Berillum2", 900, 367);
  TCanvas *c_Berillum3 = new TCanvas("c_Berillum3", "c_Berillum3", 900, 367);

  TLegend *leg3 = new TLegend(.6, .78, .9, .9, "Legenda");
  leg3->SetFillColor(0);
  leg3->AddEntry(h31_1_3, "Taglio di tipo 1", "L");
  leg3->AddEntry(h21_1_3, "Taglio di tipo 2", "L");

  TLegend *leg4 = new TLegend(.55, .82, .9, .9, "Legenda");
  leg4->SetFillColor(0);
  leg4->AddEntry(h3_1, "Distribuzione pre taglio", "L");

  c_Berillum->Divide(2, 3);
  c_Berillum1->Divide(2, 1);
  c_Berillum2->Divide(2, 1);
  c_Berillum3->Divide(2, 1);

  h3_1->GetXaxis()->SetRangeUser(4., 14.);
  h3_2->GetXaxis()->SetRangeUser(4., 14.);
  h3_3->GetXaxis()->SetRangeUser(4., 14.);
  h31_1_3->GetXaxis()->SetRangeUser(4., 14.);
  h32_2_3->GetXaxis()->SetRangeUser(4., 14.);
  h32_3_3->GetXaxis()->SetRangeUser(4., 14.);
  h21_1_3->GetXaxis()->SetRangeUser(4., 14.);
  h21_2_3->GetXaxis()->SetRangeUser(4., 14.);
  h31_3_3->GetXaxis()->SetRangeUser(4., 14.);

  c_Berillum->cd(1);
  h3_1->DrawCopy();
  leg4->Draw("same");
  c_Berillum->cd(2);
  h21_1_3->DrawCopy();
  h31_1_3->DrawCopy("same");
  leg3->Draw("same");
  c_Berillum->cd(3);
  h3_2->DrawCopy();
  leg4->Draw("same");
  c_Berillum->cd(4);
  h21_2_3->DrawCopy();
  h32_2_3->DrawCopy("same");
  leg3->Draw("same");
  c_Berillum->cd(5);
  h3_3->DrawCopy();
  leg4->Draw("same");
  c_Berillum->cd(6);
  h31_3_3->DrawCopy();
  h32_3_3->DrawCopy("same");
  leg3->Draw("same");

  c_Berillum1->cd(1);
  h3_1->DrawCopy();
  leg4->Draw("same");
  c_Berillum1->cd(2);
  h21_1_3->DrawCopy();
  h31_1_3->DrawCopy("same");
  leg3->Draw("same");

  c_Berillum2->cd(1);
  h3_2->DrawCopy();
  leg4->Draw("same");
  c_Berillum2->cd(2);
  h21_2_3->DrawCopy();
  h32_2_3->DrawCopy("same");
  leg3->Draw("same");

  c_Berillum3->cd(1);
  h3_3->DrawCopy();
  leg4->Draw("same");
  c_Berillum3->cd(2);
  h31_3_3->DrawCopy();
  h32_3_3->DrawCopy("same");
  leg3->Draw("same");

  // writing on TFile
  file2->cd();
  c_cut0->Write();
  c_cut1->Write();
  c_cut2->Write();
  c_cut3->Write();
  c_cut4->Write();
  c_cut5->Write();
  c_cut6->Write();
  c_cut7->Write();
  c_cut8->Write();
  c_cut9->Write();
  c_cut10->Write();
  c_cut11->Write();
  c_cut12->Write();
  c_cut13->Write();
  c_cut14->Write();
  c_cut15->Write();
  c_cut16->Write();
  c_cut17->Write();
  c_multigr->Write();
  c_Fcut0->Write();
  c_Fcut1->Write();
  c_Fcut2->Write();
  c_Fcut3->Write();
  c_Fcut4->Write();
  c_Fcut5->Write();
  c_Fcut6->Write();
  c_Fcut7->Write();
  c_Fcut8->Write();
  c_Fcut9->Write();
  c_Fcut10->Write();
  c_Fcut11->Write();
  c_Fcut12->Write();
  c_Fcut13->Write();
  c_Fcut14->Write();
  c_Fcut15->Write();
  c_Fcut16->Write();
  c_Fcut17->Write();
  c_cutDouble0->Write();
  c_cutDouble1->Write();
  c_cutDouble2->Write();
  c_cutDouble3->Write();
  c_cutDouble4->Write();
  c_cutDouble5->Write();
  c_cutDouble6->Write();
  c_cutDouble7->Write();
  c_cutDouble8->Write();
  c_cutDouble9->Write();
  c_cutDouble10->Write();
  c_cutDouble11->Write();
  c_cutDouble12->Write();
  c_cutDouble13->Write();
  c_cutDouble14->Write();
  c_cutDouble15->Write();
  c_cutDouble16->Write();
  c_cutDouble17->Write();
  c_MultiCanvas1->Write();
  c_MultiCanvas2->Write();
  c_MultiCanvas3->Write();
  c_MultiCanvasCut1->Write();
  c_MultiCanvasCut2->Write();
  c_MultiCanvasCut3->Write();
  c_Berillum->Write();
  c_Berillum1->Write();
  c_Berillum2->Write();
  c_Berillum3->Write();

  file2->Close();
  file1->Close();
}

int main() {
  myBestTriFit();

  return EXIT_SUCCESS;
}