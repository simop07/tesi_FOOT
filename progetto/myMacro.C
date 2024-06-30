#include "TCanvas.h"
#include "TCutG.h"
#include "TF1.h"
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
  const Double_t x0[6] = {0.708395, 1.09131,  3.44772,
                          3.10898,  0.752577, 0.708395};
  const Double_t y0[6] = {0.751152, 0.797235, 3.08602,
                          3.42396,  1.04301,  0.751152};

  const Double_t x1[6] = {2.50176, 3.06514, 4.87852, 4.31514, 2.58979, 2.50176};
  const Double_t y1[6] = {2.56548, 2.47024, 4.17262, 4.82738, 2.94643, 2.56548};

  const Double_t x2[6] = {5.6338, 6.32238, 8.98279, 8.24726, 5.6025, 5.6338};
  const Double_t y2[6] = {5.5873, 5.48148, 8, 8.74074, 5.94709, 5.5873};

  const Double_t x3[13] = {6.64789, 7.55556, 8.05634, 7.8216,  8.79186,
                           9.76213, 11.3114, 10.216,  8.93271, 8.68232,
                           7.80595, 6.50704, 6.64789};
  const Double_t y3[13] = {6.5098,  6.48802, 6.94553, 7.44662, 8.4488,
                           8.86275, 10.2353, 10.6057, 9.42919, 8.53595,
                           7.51198, 7.22876, 6.5098};

  const Double_t x4[15] = {7.7007,  9.16197, 9.83099, 11.2042, 10.9754,
                           12.4718, 12.3486, 10.7641, 10.7993, 9.65493,
                           9.63732, 9.14437, 7.80634, 7.75352, 7.7007};
  const Double_t y4[15] = {7.53571, 7.67857, 9.44048, 9.5119,  10.5119,
                           10.75,   11.4881, 11.4881, 10.4643, 10.2024,
                           9.44048, 8.25,    8.46429, 7.86905, 7.53571};

  const Double_t x5[6] = {9.46166, 10.5767, 16.5626, 12.2394, 8.15102, 9.46166};
  const Double_t y5[6] = {8.96032, 8.6164, 12.6111, 13.6958, 10.5476, 8.96032};

  const Double_t x6[6] = {0.838811, 1.03443,  3.40532,
                          3.1471,   0.838811, 0.838811};
  const Double_t y6[6] = {0.797386, 0.699346, 2.98693,
                          3.29194,  1.05882,  0.797386};

  const Double_t x7[6] = {2.625, 2.9243, 4.79049, 4.38556, 2.79225, 2.625};
  const Double_t y7[6] = {2.44643, 2.3631, 4.08929, 4.95833, 3.07738, 2.44643};

  const Double_t x8[17] = {5.68075, 6.00939, 6.47887, 6.66667, 6.99531, 8.46635,
                           8.5133,  8.16901, 7.63693, 7.37089, 7.0892,  6.90141,
                           6.55712, 6.38498, 6.10329, 5.77465, 5.68075};
  const Double_t y8[17] = {5.41799, 5.18519, 5.82011, 6.30688, 6.13757, 7.66138,
                           8.2328,  8.35979, 7.53439, 8.02116, 7.32275, 6.73016,
                           6.58201, 6.92063, 6.79365, 5.98942, 5.41799};

  const Double_t x9[17] = {6.55399, 7.13302, 7.83725, 7.99374, 8.69797, 8.94836,
                           9.68388, 9.96557, 11.1549, 10.3255, 9.79343, 9.46479,
                           8.61972, 7.99374, 7.55556, 6.41315, 6.55399};
  const Double_t y9[17] = {6.46561, 6.16931, 7.65079, 8.22222, 8.34921, 8.20106,
                           9.2381,  8.9418,  10.7196, 10.8466, 9.66138, 9.93651,
                           8.51852, 8.30688, 8.47619, 7.16402, 6.46561};

  const Double_t x10[21] = {
      7.85915, 8.12324, 9.09155, 9.79577, 9.97183, 10.5352, 10.6585,
      10.1655, 9.84859, 10.2535, 12.6303, 12.331,  11.3451, 10.7641,
      10.7289, 11.1162, 10.588,  9.76056, 8.66901, 7.87676, 7.85915};
  const Double_t y10[21] = {7.67857, 7.39286, 9.41667, 9.36905, 9.10714,
                            10.1071, 10.131,  9.17857, 8.32143, 13.0833,
                            13.5833, 11.75,   10.3452, 10.5833, 11.631,
                            11.4405, 9.63095, 9.60714, 8.25,    7.67857};

  const Double_t x11[6] = {8.46401, 11.7308, 15.5649, 13.7261, 9.2856, 8.46401};
  const Double_t y11[6] = {7.18783, 9.17196, 15.4683,
                           16.5794, 8.88095, 7.18783};

  const Double_t x12[6] = {0.791862, 0.964006, 3.42097,
                           3.01408,  0.784038, 0.791862};
  const Double_t y12[6] = {0.809524, 0.73545, 2.82011,
                           3.2963,   1.02116, 0.809524};

  const Double_t x13[6] = {2.53697, 3.10035, 4.72887, 3.92782, 2.625, 2.53697};
  const Double_t y13[6] = {2.39881, 2.375, 3.83929, 4.93452, 3.22024, 2.39881};

  const Double_t x14[19] = {5.6025,  5.86854, 6.13459, 6.27543, 6.16588,
                            6.68232, 6.90141, 7.26135, 7.2457,  8.10642,
                            8.34116, 8.05947, 7.57433, 6.65102, 6.63537,
                            5.43036, 5.759,   5.6651,  5.6025};
  const Double_t y14[19] = {5.96825, 5.01587, 4.88889, 6.24339, 6.81481,
                            6.73016, 6.28571, 6.1164,  7.06878, 7.15344,
                            7.66138, 8.84656, 7.64021, 7.89418, 6.89947,
                            7.04762, 6.87831, 6.58201, 5.96825};

  const Double_t x15[14] = {6.49139, 7.16432, 7.58685, 8.29108, 9.0892,
                            10.9358, 9.93427, 8.40063, 8.32238, 7.55556,
                            6.94523, 6.31925, 6.41315, 6.49139};
  const Double_t y15[14] = {6.38095, 6.25397, 7.82011, 8.4127,  7.96825,
                            9.4709,  11.8413, 9.34392, 8.53968, 7.8836,
                            8.56085, 7.16402, 6.7619,  6.38095};

  const Double_t x16[20] = {7.61268, 7.85915, 8.45775, 8.35211, 9.39085,
                            9.65493, 10.0423, 10.2711, 10.5352, 11.2042,
                            11.9965, 10.8873, 9.95423, 10.6232, 10.5176,
                            9.72535, 9.35563, 8.3169,  7.55986, 7.61268};
  const Double_t y16[20] = {8.36905, 7.34524, 8.67857, 9.27381, 10.1071,
                            8.79762, 8.86905, 9.65476, 10.0357, 9.77381,
                            11.9167, 12.5119, 12.0595, 12.1786, 11.25,
                            11.4881, 10.2262, 9.53571, 9.4881,  8.36905};

  const Double_t x17[6] = {8.83568, 11.6917, 15.1346,
                           11.0266, 9.18779, 8.83568};
  const Double_t y17[6] = {8.37831, 7.39947, 14.0926,
                           18.2725, 9.83333, 8.37831};

  // defining cuts
  TCutG *myCut0 = new TCutG("myCut0", 6, x0, y0);
  TCutG *myCut1 = new TCutG("myCut1", 6, x1, y1);
  TCutG *myCut2 = new TCutG("myCut2", 6, x2, y2);
  TCutG *myCut3 = new TCutG("myCut3", 13, x3, y3);
  TCutG *myCut4 = new TCutG("myCut4", 15, x4, y4);
  TCutG *myCut5 = new TCutG("myCut5", 6, x5, y5);
  TCutG *myCut6 = new TCutG("myCut6", 6, x6, y6);
  TCutG *myCut7 = new TCutG("myCut7", 6, x7, y7);
  TCutG *myCut8 = new TCutG("myCut8", 17, x8, y8);
  TCutG *myCut9 = new TCutG("myCut9", 17, x9, y9);
  TCutG *myCut10 = new TCutG("myCut10", 21, x10, y10);
  TCutG *myCut11 = new TCutG("myCut11", 6, x11, y11);
  TCutG *myCut12 = new TCutG("myCut12", 6, x12, y12);
  TCutG *myCut13 = new TCutG("myCut13", 6, x13, y13);
  TCutG *myCut14 = new TCutG("myCut14", 19, x14, y14);
  TCutG *myCut15 = new TCutG("myCut15", 14, x15, y15);
  TCutG *myCut16 = new TCutG("myCut16", 20, x16, y16);
  TCutG *myCut17 = new TCutG("myCut17", 6, x17, y17);

  // creating and filling 1D histos
  // histo0
  TH1D *h21_1_0 = new TH1D("h21_1_0", "{}_{1}H; A_{1}; Entries", 300, 0., 8.);
  h21_1_0 = h_Acor0->ProjectionX("h21_1_0", 0, -1, "[myCut0]");

  TH1D *h21_2_0 = new TH1D("h21_2_0", "{}_{1}H; A_{2}; Entries", 300, 0., 8.);
  h21_2_0 = h_Acor0->ProjectionY("h21_2_0", 0, -1, "[myCut0]");

  TH1D *h31_1_0 = new TH1D("h31_1_0", "{}_{1}H; A_{1}; Entries", 300, 0., 8.);
  h31_1_0 = h_Acor6->ProjectionX("h31_1_0", 0, -1, "[myCut6]");

  TH1D *h31_3_0 = new TH1D("h31_3_0", "{}_{1}H; A_{3}; Entries", 300, 0., 8.);
  h31_3_0 = h_Acor6->ProjectionY("h31_3_0", 0, -1, "[myCut6]");

  TH1D *h32_2_0 = new TH1D("h32_2_0", "{}_{1}H; A_{2}; Entries", 300, 0., 8.);
  h32_2_0 = h_Acor12->ProjectionX("h32_2_0", 0, -1, "[myCut12]");

  TH1D *h32_3_0 = new TH1D("h32_3_0", "{}_{1}H; A_{3}; Entries", 300, 0., 8.);
  h32_3_0 = h_Acor12->ProjectionY("h32_3_0", 0, -1, "[myCut12]");

  // histo1
  TH1D *h21_1_1 = new TH1D("h21_1_1", "{}_{2}He; A_{1}; Entries", 300, 0., 9.);
  h21_1_1 = h_Acor1->ProjectionX("h21_1_1", 0, -1, "[myCut1]");

  TH1D *h21_2_1 = new TH1D("h21_2_1", "{}_{2}He; A_{2}; Entries", 300, 0., 9.);
  h21_2_1 = h_Acor1->ProjectionY("h21_2_1", 0, -1, "[myCut1]");

  TH1D *h31_1_1 = new TH1D("h31_1_1", "{}_{2}He; A_{1}; Entries", 300, 0., 9.);
  h31_1_1 = h_Acor7->ProjectionX("h31_1_1", 0, -1, "[myCut7]");

  TH1D *h31_3_1 = new TH1D("h31_3_1", "{}_{2}He; A_{3}; Entries", 300, 0., 9.);
  h31_3_1 = h_Acor7->ProjectionY("h31_3_1", 0, -1, "[myCut7]");

  TH1D *h32_2_1 = new TH1D("h32_2_1", "{}_{2}He; A_{2}; Entries", 300, 0., 9.);
  h32_2_1 = h_Acor13->ProjectionX("h32_2_1", 0, -1, "[myCut13]");

  TH1D *h32_3_1 = new TH1D("h32_3_1", "{}_{2}He; A_{3}; Entries", 300, 0., 9.);
  h32_3_1 = h_Acor13->ProjectionY("h32_3_1", 0, -1, "[myCut13]");

  // histo2
  TH1D *h21_1_2 = new TH1D("h21_1_2", "{}_{3}Li; A_{1}; Entries", 300, 2., 18.);
  h21_1_2 = h_Acor2->ProjectionX("h21_1_2", 0, -1, "[myCut2]");

  TH1D *h21_2_2 = new TH1D("h21_2_2", "{}_{3}Li; A_{2}; Entries", 300, 2., 18.);
  h21_2_2 = h_Acor2->ProjectionY("h21_2_2", 0, -1, "[myCut2]");

  TH1D *h31_1_2 = new TH1D("h31_1_2", "{}_{3}Li; A_{1}; Entries", 300, 2., 18.);
  h31_1_2 = h_Acor8->ProjectionX("h31_1_2", 0, -1, "[myCut8]");

  TH1D *h31_3_2 = new TH1D("h31_3_2", "{}_{3}Li; A_{3}; Entries", 300, 2., 18.);
  h31_3_2 = h_Acor8->ProjectionY("h31_3_2", 0, -1, "[myCut8]");

  TH1D *h32_2_2 = new TH1D("h32_2_2", "{}_{3}Li; A_{2}; Entries", 300, 2., 18.);
  h32_2_2 = h_Acor14->ProjectionX("h32_2_2", 0, -1, "[myCut14]");

  TH1D *h32_3_2 = new TH1D("h32_3_2", "{}_{3}Li; A_{3}; Entries", 300, 2., 18.);
  h32_3_2 = h_Acor14->ProjectionY("h32_3_2", 0, -1, "[myCut14]");

  // histo3
  TH1D *h21_1_3 = new TH1D("h21_1_3", "{}_{4}Be; A_{1}; Entries", 300, 4., 20.);
  h21_1_3 = h_Acor3->ProjectionX("h21_1_3", 0, -1, "[myCut3]");

  TH1D *h21_2_3 = new TH1D("h21_2_3", "{}_{4}Be; A_{2}; Entries", 300, 4., 20.);
  h21_2_3 = h_Acor3->ProjectionY("h21_2_3", 0, -1, "[myCut3]");

  TH1D *h31_1_3 = new TH1D("h31_1_3", "{}_{4}Be; A_{1}; Entries", 300, 4., 20.);
  h31_1_3 = h_Acor9->ProjectionX("h31_1_3", 0, -1, "[myCut9]");

  TH1D *h31_3_3 = new TH1D("h31_3_3", "{}_{4}Be; A_{3}; Entries", 300, 4., 20.);
  h31_3_3 = h_Acor9->ProjectionY("h31_3_3", 0, -1, "[myCut9]");

  TH1D *h32_2_3 = new TH1D("h32_2_3", "{}_{4}Be; A_{2}; Entries", 300, 4., 20.);
  h32_2_3 = h_Acor15->ProjectionX("h32_2_3", 0, -1, "[myCut15]");

  TH1D *h32_3_3 = new TH1D("h32_3_3", "{}_{4}Be; A_{3}; Entries", 300, 4., 20.);
  h32_3_3 = h_Acor15->ProjectionY("h32_3_3", 0, -1, "[myCut15]");

  // histo4
  TH1D *h21_1_4 = new TH1D("h21_1_4", "{}_{5}B; A_{1}; Entries", 300, 4., 22.);
  h21_1_4 = h_Acor4->ProjectionX("h21_1_4", 0, -1, "[myCut4]");

  TH1D *h21_2_4 = new TH1D("h21_2_4", "{}_{5}B; A_{2}; Entries", 300, 4., 22.);
  h21_2_4 = h_Acor4->ProjectionY("h21_2_4", 0, -1, "[myCut4]");

  TH1D *h31_1_4 = new TH1D("h31_1_4", "{}_{5}B; A_{1}; Entries", 300, 4., 22.);
  h31_1_4 = h_Acor10->ProjectionX("h31_1_4", 0, -1, "[myCut10]");

  TH1D *h31_3_4 = new TH1D("h31_3_4", "{}_{5}B; A_{3}; Entries", 300, 4., 22.);
  h31_3_4 = h_Acor10->ProjectionY("h31_3_4", 0, -1, "[myCut10]");

  TH1D *h32_2_4 = new TH1D("h32_2_4", "{}_{5}B; A_{2}; Entries", 300, 4., 22.);
  h32_2_4 = h_Acor16->ProjectionX("h32_2_4", 0, -1, "[myCut16]");

  TH1D *h32_3_4 = new TH1D("h32_3_4", "{}_{5}B; A_{3}; Entries", 300, 4., 22.);
  h32_3_4 = h_Acor16->ProjectionY("h32_3_4", 0, -1, "[myCut16]");

  // histo5
  TH1D *h21_1_5 = new TH1D("h21_1_5", "{}_{6}C; A_{1}; Entries", 300, 4., 24.);
  h21_1_5 = h_Acor5->ProjectionX("h21_1_5", 0, -1, "[myCut5]");

  TH1D *h21_2_5 = new TH1D("h21_2_5", "{}_{6}C; A_{2}; Entries", 300, 4., 24.);
  h21_2_5 = h_Acor5->ProjectionY("h21_2_5", 0, -1, "[myCut5]");

  TH1D *h31_1_5 = new TH1D("h31_1_5", "{}_{6}C; A_{1}; Entries", 300, 4., 24.);
  h31_1_5 = h_Acor11->ProjectionX("h31_1_5", 0, -1, "[myCut11]");

  TH1D *h31_3_5 = new TH1D("h31_3_5", "{}_{6}C; A_{3}; Entries", 300, 4., 24.);
  h31_3_5 = h_Acor11->ProjectionY("h31_3_5", 0, -1, "[myCut11]");

  TH1D *h32_2_5 = new TH1D("h32_2_5", "{}_{6}C; A_{2}; Entries", 300, 4., 24.);
  h32_2_5 = h_Acor17->ProjectionX("h32_2_5", 0, -1, "[myCut17]");

  TH1D *h32_3_5 = new TH1D("h32_3_5", "{}_{6}C; A_{3}; Entries", 300, 4., 24.);
  h32_3_5 = h_Acor17->ProjectionY("h32_3_5", 0, -1, "[myCut17]");

  // fit functions
  // histo0
  TF1 *f_cut0_1 = new TF1("f_cut0_1", "gaus", 0.5, 1.5);
  TF1 *f_cut0_2 = new TF1("f_cut0_2", "gaus", 1.5, 2.5);
  TF1 *f_cut0_3 = new TF1("f_cut0_3", "gaus", 2.5, 3.5);
  TF1 *f_cut0_tot = new TF1("f_cut0_tot", "gaus(0)+gaus(3)+gaus(6)", 0.5, 3.5);
  Double_t par0[9];

  TF1 *f_cut1_1 = new TF1("f_cut1_1", "gaus", 2., 3.5);
  TF1 *f_cut1_2 = new TF1("f_cut1_2", "gaus", 3.5, 5.);
  TF1 *f_cut1_tot = new TF1("f_cut1_tot", "gaus(0)+gaus(3)", 2., 5.);
  Double_t par1[6];

  // cosmetics
  f_cut0_1->SetLineColor(kRed);
  f_cut0_1->SetLineWidth(3);
  f_cut0_1->SetLineStyle(2);

  f_cut0_2->SetLineColor(kRed);
  f_cut0_2->SetLineWidth(3);
  f_cut0_2->SetLineStyle(2);

  f_cut0_3->SetLineColor(kRed);
  f_cut0_3->SetLineWidth(3);
  f_cut0_3->SetLineStyle(2);

  f_cut0_tot->SetLineColor(kOrange);
  f_cut0_tot->SetLineWidth(3);
  f_cut0_tot->SetLineStyle(2);

  f_cut1_1->SetLineColor(kRed);
  f_cut1_1->SetLineWidth(3);
  f_cut1_1->SetLineStyle(2);

  f_cut1_2->SetLineColor(kRed);
  f_cut1_2->SetLineWidth(3);
  f_cut1_2->SetLineStyle(2);

  f_cut1_tot->SetLineColor(kOrange);
  f_cut1_tot->SetLineWidth(3);
  f_cut1_tot->SetLineStyle(2);

  // setting parameters
  f_cut0_1->SetParameter(1, 1);
  f_cut0_2->SetParameter(1, 1);
  f_cut0_3->SetParameter(1, 1);

  f_cut0_1->SetParameter(2, 0.5);
  f_cut0_2->SetParameter(2, 0.5);
  f_cut0_3->SetParameter(2, 0.5);

  f_cut1_1->SetParameter(1, 3);
  f_cut1_2->SetParameter(1, 4);

  f_cut1_1->SetParameter(2, 0.5);
  f_cut1_2->SetParameter(2, 0.5);

  // fitting
  h31_1_0->Fit(f_cut0_1, "R");
  h31_1_0->Fit(f_cut0_2, "R+");
  h31_1_0->Fit(f_cut0_3, "R+");

  h32_2_0->Fit(f_cut0_1, "R");
  h32_2_0->Fit(f_cut0_2, "R+");
  h32_2_0->Fit(f_cut0_3, "R+");

  h32_3_0->Fit(f_cut0_1, "R");
  h32_3_0->Fit(f_cut0_2, "R+");
  h32_3_0->Fit(f_cut0_3, "R+");

  f_cut0_1->GetParameters(&par0[0]);
  f_cut0_2->GetParameters(&par0[3]);
  f_cut0_3->GetParameters(&par0[6]);

  f_cut0_tot->SetParameters(par0);
  h31_1_0->Fit(f_cut0_tot, "R+");
  h32_2_0->Fit(f_cut0_tot, "R+");
  h32_3_0->Fit(f_cut0_tot, "R+");

  h31_1_1->Fit(f_cut1_1, "R");
  h31_1_1->Fit(f_cut1_2, "R+");

  h32_2_1->Fit(f_cut1_1, "R");
  h32_2_1->Fit(f_cut1_2, "R+");

  h32_3_1->Fit(f_cut1_1, "R");
  h32_3_1->Fit(f_cut1_2, "R+");

  f_cut1_1->GetParameters(&par1[0]);
  f_cut1_2->GetParameters(&par1[3]);

  f_cut1_tot->SetParameters(par1);
  h31_1_1->Fit(f_cut1_tot, "R+");
  h32_2_1->Fit(f_cut1_tot, "R+");
  h32_3_1->Fit(f_cut1_tot, "R+");

  // drawing on canvas and cosmetics
  // histo0
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

  // histo1
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
  file1->Close();
}

int main() {
  myMacro();

  return EXIT_SUCCESS;
}