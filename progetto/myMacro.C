// To compile in SHELL: "g++ myMacro.C `root-config --cflags --libs`"

#include "TCanvas.h"
#include "TCutG.h"
#include "TFile.h"
#include "TH2.h"
#include "TLatex.h"
#include "TPad.h"
#include "TROOT.h"
#include "TStyle.h"

void setFitStyle() {
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

void myMacro() {
  setFitStyle();
  // Loading ROOT File
  TFile *file1 = new TFile("myAnalysis.root", "READ");

  // Creating ROOT File
  TFile *file2 = new TFile("analisi/myMacro.root", "RECREATE");

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

  // defining arrays for cuts
  const Double_t x0[6] = {};
  const Double_t y0[6] = {};
  const Double_t x1[6] = {};
  const Double_t y1[6] = {};
  const Double_t x2[6] = {};
  const Double_t y2[6] = {};
  const Double_t x3[6] = {};
  const Double_t y3[6] = {};
  const Double_t x4[6] = {};
  const Double_t y4[6] = {};
  const Double_t x5[6] = {};
  const Double_t y5[6] = {};
  const Double_t x6[6] = {};
  const Double_t y6[6] = {};
  const Double_t x7[6] = {};
  const Double_t y7[6] = {};
  const Double_t x8[6] = {};
  const Double_t y8[6] = {};
  const Double_t x9[6] = {};
  const Double_t y9[6] = {};
  const Double_t x10[6] = {};
  const Double_t y10[6] = {};
  const Double_t x11[6] = {};
  const Double_t y11[6] = {};
  const Double_t x12[6] = {};
  const Double_t y12[6] = {};
  const Double_t x13[6] = {};
  const Double_t y13[6] = {};
  const Double_t x14[6] = {};
  const Double_t y14[6] = {};
  const Double_t x15[6] = {};
  const Double_t y15[6] = {};
  const Double_t x16[6] = {};
  const Double_t y16[6] = {};
  const Double_t x17[6] = {};
  const Double_t y17[6] = {};

  // defining cuts
  TCutG *myCut0 = new TCutG("myCut1", 6, x0, y0);
  TCutG *myCut1 = new TCutG("myCut1", 6, x1, y1);
  TCutG *myCut2 = new TCutG("myCut2", 6, x2, y2);
  TCutG *myCut3 = new TCutG("myCut3", 6, x3, y3);
  TCutG *myCut4 = new TCutG("myCut4", 6, x4, y4);
  TCutG *myCut5 = new TCutG("myCut5", 6, x5, y5);
  TCutG *myCut6 = new TCutG("myCut6", 6, x6, y6);
  TCutG *myCut7 = new TCutG("myCut7", 6, x7, y7);
  TCutG *myCut8 = new TCutG("myCut8", 6, x8, y8);
  TCutG *myCut9 = new TCutG("myCut9", 6, x9, y9);
  TCutG *myCut10 = new TCutG("myCut10", 6, x10, y10);
  TCutG *myCut11 = new TCutG("myCut11", 6, x11, y11);
  TCutG *myCut12 = new TCutG("myCut12", 6, x12, y12);
  TCutG *myCut13 = new TCutG("myCut13", 6, x13, y13);
  TCutG *myCut14 = new TCutG("myCut14", 6, x14, y14);
  TCutG *myCut15 = new TCutG("myCut15", 6, x15, y15);
  TCutG *myCut16 = new TCutG("myCut16", 6, x16, y16);
  TCutG *myCut17 = new TCutG("myCut17", 6, x17, y17);

  // creating and filling 1D histos
  // histo0
  TH1D *h21_1_0 = new TH1D("h21_1_0", "{}_{1}H; A_{1}; Entries", 300, 0., 8.);
  h21_1_0 = h_Acor0->ProjectionX("h21_1_0", 0, -1);

  TH1D *h21_2_0 = new TH1D("h21_2_0", "{}_{1}H; A_{2}; Entries", 300, 0., 8.);
  h21_2_0 = h_Acor0->ProjectionY("h21_2_0", 0, -1);

  TH1D *h31_1_0 = new TH1D("h31_1_0", "{}_{1}H; A_{1}; Entries", 300, 0., 8.);
  h31_1_0 = h_Acor6->ProjectionX("h31_1_0", 0, -1);

  TH1D *h31_3_0 = new TH1D("h31_3_0", "{}_{1}H; A_{3}; Entries", 300, 0., 8.);
  h31_3_0 = h_Acor6->ProjectionY("h31_3_0", 0, -1);

  TH1D *h32_2_0 = new TH1D("h32_2_0", "{}_{1}H; A_{2}; Entries", 300, 0., 8.);
  h32_2_0 = h_Acor12->ProjectionX("h32_2_0", 0, -1);

  TH1D *h32_3_0 = new TH1D("h32_3_0", "{}_{1}H; A_{3}; Entries", 300, 0., 8.);
  h32_3_0 = h_Acor12->ProjectionY("h32_3_0", 0, -1);

  // histo1
  TH1D *h21_1_1 = new TH1D("h21_1_1", "{}_{2}He; A_{1}; Entries", 300, 0., 9.);
  h21_1_1 = h_Acor1->ProjectionX("h21_1_1", 0, -1);

  TH1D *h21_2_1 = new TH1D("h21_2_1", "{}_{2}He; A_{2}; Entries", 300, 0., 9.);
  h21_2_1 = h_Acor1->ProjectionY("h21_2_1", 0, -1);

  TH1D *h31_1_1 = new TH1D("h31_1_1", "{}_{2}He; A_{1}; Entries", 300, 0., 9.);
  h31_1_1 = h_Acor7->ProjectionX("h31_1_1", 0, -1);

  TH1D *h31_3_1 = new TH1D("h31_3_1", "{}_{2}He; A_{3}; Entries", 300, 0., 9.);
  h31_3_1 = h_Acor7->ProjectionY("h31_3_1", 0, -1);

  TH1D *h32_2_1 = new TH1D("h32_2_1", "{}_{2}He; A_{2}; Entries", 300, 0., 9.);
  h32_2_1 = h_Acor13->ProjectionX("h32_2_1", 0, -1);

  TH1D *h32_3_1 = new TH1D("h32_3_1", "{}_{2}He; A_{3}; Entries", 300, 0., 9.);
  h32_3_1 = h_Acor13->ProjectionY("h32_3_1", 0, -1);

  // histo2
  TH1D *h21_1_2 = new TH1D("h21_1_2", "{}_{3}Li; A_{1}; Entries", 300, 2., 18.);
  h21_1_2 = h_Acor2->ProjectionX("h21_1_2", 0, -1);

  TH1D *h21_2_2 = new TH1D("h21_2_2", "{}_{3}Li; A_{2}; Entries", 300, 2., 18.);
  h21_2_2 = h_Acor2->ProjectionY("h21_2_2", 0, -1);

  TH1D *h31_1_2 = new TH1D("h31_1_2", "{}_{3}Li; A_{1}; Entries", 300, 2., 18.);
  h31_1_2 = h_Acor8->ProjectionX("h31_1_2", 0, -1);

  TH1D *h31_3_2 = new TH1D("h31_3_2", "{}_{3}Li; A_{3}; Entries", 300, 2., 18.);
  h31_3_2 = h_Acor8->ProjectionY("h31_3_2", 0, -1);

  TH1D *h32_2_2 = new TH1D("h32_2_2", "{}_{3}Li; A_{2}; Entries", 300, 2., 18.);
  h32_2_2 = h_Acor14->ProjectionX("h32_2_2", 0, -1);

  TH1D *h32_3_2 = new TH1D("h32_3_2", "{}_{3}Li; A_{3}; Entries", 300, 2., 18.);
  h32_3_2 = h_Acor14->ProjectionY("h32_3_2", 0, -1);

  // histo3
  TH1D *h21_1_3 = new TH1D("h21_1_3", "{}_{4}Be; A_{1}; Entries", 300, 4., 20.);
  h21_1_3 = h_Acor3->ProjectionX("h21_1_3", 0, -1);

  TH1D *h21_2_3 = new TH1D("h21_2_3", "{}_{4}Be; A_{2}; Entries", 300, 4., 20.);
  h21_2_3 = h_Acor3->ProjectionY("h21_2_3", 0, -1);

  TH1D *h31_1_3 = new TH1D("h31_1_3", "{}_{4}Be; A_{1}; Entries", 300, 4., 20.);
  h31_1_3 = h_Acor9->ProjectionX("h31_1_3", 0, -1);

  TH1D *h31_3_3 = new TH1D("h31_3_3", "{}_{4}Be; A_{3}; Entries", 300, 4., 20.);
  h31_3_3 = h_Acor9->ProjectionY("h31_3_3", 0, -1);

  TH1D *h32_2_3 = new TH1D("h32_2_3", "{}_{4}Be; A_{2}; Entries", 300, 4., 20.);
  h32_2_3 = h_Acor15->ProjectionX("h32_2_3", 0, -1);

  TH1D *h32_3_3 = new TH1D("h32_3_3", "{}_{4}Be; A_{3}; Entries", 300, 4., 20.);
  h32_3_3 = h_Acor15->ProjectionY("h32_3_3", 0, -1);

  // histo4
  TH1D *h21_1_4 = new TH1D("h21_1_4", "{}_{5}B; A_{1}; Entries", 300, 4., 22.);
  h21_1_4 = h_Acor4->ProjectionX("h21_1_4", 0, -1);

  TH1D *h21_2_4 = new TH1D("h21_2_4", "{}_{5}B; A_{2}; Entries", 300, 4., 22.);
  h21_2_4 = h_Acor4->ProjectionY("h21_2_4", 0, -1);

  TH1D *h31_1_4 = new TH1D("h31_1_4", "{}_{5}B; A_{1}; Entries", 300, 4., 22.);
  h31_1_4 = h_Acor10->ProjectionX("h31_1_4", 0, -1);

  TH1D *h31_3_4 = new TH1D("h31_3_4", "{}_{5}B; A_{3}; Entries", 300, 4., 22.);
  h31_3_4 = h_Acor10->ProjectionY("h31_3_4", 0, -1);

  TH1D *h32_2_4 = new TH1D("h32_2_4", "{}_{5}B; A_{2}; Entries", 300, 4., 22.);
  h32_2_4 = h_Acor16->ProjectionX("h32_2_4", 0, -1);

  TH1D *h32_3_4 = new TH1D("h32_3_4", "{}_{5}B; A_{3}; Entries", 300, 4., 22.);
  h32_3_4 = h_Acor16->ProjectionY("h32_3_4", 0, -1);

  // histo5
  TH1D *h21_1_5 = new TH1D("h21_1_5", "{}_{6}C; A_{1}; Entries", 300, 4., 24.);
  h21_1_5 = h_Acor5->ProjectionX("h21_1_5", 0, -1);

  TH1D *h21_2_5 = new TH1D("h21_2_5", "{}_{6}C; A_{2}; Entries", 300, 4., 24.);
  h21_2_5 = h_Acor5->ProjectionY("h21_2_5", 0, -1);

  TH1D *h31_1_5 = new TH1D("h31_1_5", "{}_{6}C; A_{1}; Entries", 300, 4., 24.);
  h31_1_5 = h_Acor11->ProjectionX("h31_1_5", 0, -1);

  TH1D *h31_3_5 = new TH1D("h31_3_5", "{}_{6}C; A_{3}; Entries", 300, 4., 24.);
  h31_3_5 = h_Acor11->ProjectionY("h31_3_5", 0, -1);

  TH1D *h32_2_5 = new TH1D("h32_2_5", "{}_{6}C; A_{2}; Entries", 300, 4., 24.);
  h32_2_5 = h_Acor17->ProjectionX("h32_2_5", 0, -1);

  TH1D *h32_3_5 = new TH1D("h32_3_5", "{}_{6}C; A_{3}; Entries", 300, 4., 24.);
  h32_3_5 = h_Acor17->ProjectionY("h32_3_5", 0, -1);

  // drawing on canvas and cosmetics
  h21_1_0->SetLineColor(kBlue);
  h31_1_0->SetLineColor(kBlack);
  c_cut0->cd();
  h21_1_0->Draw();
  h31_1_0->Draw("same");

  h21_2_0->SetLineColor(kBlue);
  h32_2_0->SetLineColor(kBlack);
  c_cut1->cd();
  h21_2_0->Draw();
  h32_2_0->Draw("same");

  h31_3_0->SetLineColor(kBlue);
  h32_3_0->SetLineColor(kBlack);
  c_cut2->cd();
  h31_3_0->Draw();
  h32_3_0->Draw("same");

  h21_1_1->SetLineColor(kBlue);
  h31_1_1->SetLineColor(kBlack);
  c_cut3->cd();
  h21_1_1->Draw();
  h31_1_1->Draw("same");

  h21_2_1->SetLineColor(kBlue);
  h32_2_1->SetLineColor(kBlack);
  c_cut4->cd();
  h21_2_1->Draw();
  h32_2_1->Draw("same");

  h31_3_1->SetLineColor(kBlue);
  h32_3_1->SetLineColor(kBlack);
  c_cut5->cd();
  h31_3_1->Draw();
  h32_3_1->Draw("same");

  h21_1_2->SetLineColor(kBlue);
  h31_1_2->SetLineColor(kBlack);
  c_cut6->cd();
  h21_1_2->Draw();
  h31_1_2->Draw("same");

  h21_2_2->SetLineColor(kBlue);
  h32_2_2->SetLineColor(kBlack);
  c_cut7->cd();
  h21_2_2->Draw();
  h32_2_2->Draw("same");

  h31_3_2->SetLineColor(kBlue);
  h32_3_2->SetLineColor(kBlack);
  c_cut8->cd();
  h31_3_2->Draw();
  h32_3_2->Draw("same");

  h21_1_3->SetLineColor(kBlue);
  h31_1_3->SetLineColor(kBlack);
  c_cut9->cd();
  h21_1_3->Draw();
  h31_1_3->Draw("same");

  h21_2_3->SetLineColor(kBlue);
  h32_2_3->SetLineColor(kBlack);
  c_cut10->cd();
  h21_2_3->Draw();
  h32_2_3->Draw("same");

  h31_3_3->SetLineColor(kBlue);
  h32_3_3->SetLineColor(kBlack);
  c_cut11->cd();
  h31_3_3->Draw();
  h32_3_3->Draw("same");

  h21_1_4->SetLineColor(kBlue);
  h31_1_4->SetLineColor(kBlack);
  c_cut12->cd();
  h21_1_4->Draw();
  h31_1_4->Draw("same");

  h21_2_4->SetLineColor(kBlue);
  h32_2_4->SetLineColor(kBlack);
  c_cut13->cd();
  h21_2_4->Draw();
  h32_2_4->Draw("same");

  h31_3_4->SetLineColor(kBlue);
  h32_3_4->SetLineColor(kBlack);
  c_cut14->cd();
  h31_3_4->Draw();
  h32_3_4->Draw("same");

  h21_1_5->SetLineColor(kBlue);
  h31_1_5->SetLineColor(kBlack);
  c_cut15->cd();
  h21_1_5->Draw();
  h31_1_5->Draw("same");

  h21_2_5->SetLineColor(kBlue);
  h32_2_5->SetLineColor(kBlack);
  c_cut16->cd();
  h21_2_5->Draw();
  h32_2_5->Draw("same");

  h31_3_5->SetLineColor(kBlue);
  h32_3_5->SetLineColor(kBlack);
  c_cut17->cd();
  h31_3_5->Draw();
  h32_3_5->Draw("same");

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
  file2->Close();
}

int main() {
  myMacro();

  return EXIT_SUCCESS;
}