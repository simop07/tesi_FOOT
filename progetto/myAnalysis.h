//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May  1 16:37:06 2024 by ROOT version 6.30/04
// from TTree OuTree/Reco Event Tree
// found on file: Merge_12C_200_2023v2_1_ntu.root
//////////////////////////////////////////////////////////

#ifndef MYANALYSIS_H
#define MYANALYSIS_H

#include <vector>

#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TROOT.h"
#include "TVector3.h"

// Header file for the classes stored in the TTree if any.

class myAnalysis {
 public:
  TTree *fChain;   //! pointer to the analyzed TTree or TChain
  Int_t fCurrent;  //! current Tree number in a TChain

  // Fixed size dimensions of array or collections stored in the TTree if any.

  // Declaration of leaf types
  Int_t ev;
  Int_t vertex_n;
  std::vector<float> *vertex_x;
  std::vector<float> *vertex_y;
  std::vector<float> *vertex_z;
  std::vector<int> *vt_trk_n;
  std::vector<float> *vt_trk_chi2;
  std::vector<TVector3> *vt_trk_slopez;
  std::vector<TVector3> *vt_trk_origin;
  std::vector<TVector3> *vt_trk_projTW;
  std::vector<int> *vt_trk_clus_n;
  std::vector<int> *trk_vtx_clus_MCId;
  std::vector<int> *vt_trk_clus_tot_hits;
  std::vector<float> *vt_trk_clus_x;
  std::vector<float> *vt_trk_clus_y;
  std::vector<float> *vt_trk_clus_z;
  std::vector<int> *vt_clus_n;
  std::vector<int> *vtx_clus_MCId;
  std::vector<int> *vt_clus_tot_hits;
  std::vector<float> *vt_clus_x;
  std::vector<float> *vt_clus_y;
  std::vector<float> *vt_clus_z;
  std::vector<float> *vt_clus_MC;
  std::vector<int> *msd_station_id;
  std::vector<int> *msd_pt_n;
  std::vector<int> *msd_pt_MCId;
  std::vector<double> *msd_eloss1;
  std::vector<double> *msd_eloss2;
  std::vector<TVector3> *msd_pos;
  std::vector<int> *msd_station_clus_id;
  std::vector<int> *msd_clus_n;
  std::vector<int> *msd_clus_MCId;
  std::vector<double> *msd_eloss;
  std::vector<TVector3> *msd_clus_pos;
  Int_t TWPoints;
  std::vector<int> *TWChargePoint;
  std::vector<int> *TATW_MCID_1;
  std::vector<int> *TATW_MCID_2;
  std::vector<double> *TWDe1Point;
  std::vector<double> *TWDe2Point;
  std::vector<double> *TWXPoint;
  std::vector<double> *TWYPoint;
  std::vector<double> *TWZPoint;
  Int_t TWHit;
  std::vector<double> *TWDeHit;
  std::vector<int> *TW_MCID_hit;
  std::vector<double> *TWTOFHit;
  std::vector<double> *TWbarHit;
  std::vector<double> *TWlayerHit;
  std::vector<double> *TWTOF;
  std::vector<double> *TWTOF1;
  std::vector<double> *TWTOF2;
  Int_t CAclusN;
  std::vector<double> *CAenergy;
  std::vector<double> *CAposX;
  std::vector<double> *CAposY;
  std::vector<double> *CAposZ;
  Int_t GLBtracks;
  std::vector<double> *GLBtrackPx;
  std::vector<double> *GLBtrackPy;
  std::vector<double> *GLBtrackPz;
  std::vector<double> *GLBtrackLength;
  std::vector<int> *GLBtrackTWid;
  std::vector<int> *GLBtrackCAid;
  std::vector<int> *MC_Dead_region;
  std::vector<int> *MC_Generation_region;
  std::vector<int> *MC_FlukaID;
  std::vector<int> *MC_MotherID;
  std::vector<int> *MC_BaryonN;
  std::vector<double> *MC_Mass;
  std::vector<int> *MC_Ptype;
  std::vector<int> *MC_Charge;
  std::vector<double> *MC_TOF;
  std::vector<double> *MC_Track_Length;
  std::vector<float> *MC_InitPos_x;
  std::vector<float> *MC_InitPos_y;
  std::vector<float> *MC_InitPos_z;
  std::vector<float> *MC_FinalPos_x;
  std::vector<float> *MC_FianlPos_y;
  std::vector<float> *MC_FinalPos_z;
  std::vector<float> *MC_InitMom_x;
  std::vector<float> *MC_InitMom_y;
  std::vector<float> *MC_InitMom_z;
  std::vector<float> *MC_FinalMom_x;
  std::vector<float> *MC_FinalMom_y;
  std::vector<float> *MC_FinalMom_z;

  // List of branches
  TBranch *b_ev;                    //!
  TBranch *b_vertex_n;              //!
  TBranch *b_vertex_x;              //!
  TBranch *b_vertex_y;              //!
  TBranch *b_vertex_z;              //!
  TBranch *b_vt_trk_n;              //!
  TBranch *b_vt_trk_chi2;           //!
  TBranch *b_vt_trk_slopez;         //!
  TBranch *b_vt_trk_origin;         //!
  TBranch *b_vt_trk_projTW;         //!
  TBranch *b_vt_trk_clus_n;         //!
  TBranch *b_trk_vtx_clus_MCId;     //!
  TBranch *b_vt_trk_clus_tot_hits;  //!
  TBranch *b_vt_trk_clus_x;         //!
  TBranch *b_vt_trk_clus_y;         //!
  TBranch *b_vt_trk_clus_z;         //!
  TBranch *b_vt_clus_n;             //!
  TBranch *b_vtx_clus_MCId;         //!
  TBranch *b_vt_clus_tot_hits;      //!
  TBranch *b_vt_clus_x;             //!
  TBranch *b_vt_clus_y;             //!
  TBranch *b_vt_clus_z;             //!
  TBranch *b_vt_clus_MC;            //!
  TBranch *b_msd_station_id;        //!
  TBranch *b_msd_pt_n;              //!
  TBranch *b_msd_pt_MCId;           //!
  TBranch *b_msd_eloss1;            //!
  TBranch *b_msd_eloss2;            //!
  TBranch *b_msd_pos;               //!
  TBranch *b_msd_station_clus_id;   //!
  TBranch *b_msd_clus_n;            //!
  TBranch *b_msd_clus_MCId;         //!
  TBranch *b_msd_eloss;             //!
  TBranch *b_msd_clus_pos;          //!
  TBranch *b_TWPoints;              //!
  TBranch *b_TWChargePoint;         //!
  TBranch *b_TATW_MCID_1;           //!
  TBranch *b_TATW_MCID_2;           //!
  TBranch *b_TWDe1Point;            //!
  TBranch *b_TWDe2Point;            //!
  TBranch *b_TWXPoint;              //!
  TBranch *b_TWYPoint;              //!
  TBranch *b_TWZPoint;              //!
  TBranch *b_TWHit;                 //!
  TBranch *b_TWDeHit;               //!
  TBranch *b_TW_MCID_hit;           //!
  TBranch *b_TWTOFHit;              //!
  TBranch *b_TWbarHit;              //!
  TBranch *b_TWlayerHit;            //!
  TBranch *b_TWTOF;                 //!
  TBranch *b_TWTOF1;                //!
  TBranch *b_TWTOF2;                //!
  TBranch *b_CAclusN;               //!
  TBranch *b_CAenergy;              //!
  TBranch *b_CAposX;                //!
  TBranch *b_CAposY;                //!
  TBranch *b_CAposZ;                //!
  TBranch *b_GLBtracks;             //!
  TBranch *b_GLBtrackPx;            //!
  TBranch *b_GLBtrackPy;            //!
  TBranch *b_GLBtrackPz;            //!
  TBranch *b_GLBtrackLength;        //!
  TBranch *b_GLBtrackTWid;          //!
  TBranch *b_GLBtrackCAid;          //!
  TBranch *b_MC_Dead_region;        //!
  TBranch *b_MC_Generation_region;  //!
  TBranch *b_MC_FlukaID;            //!
  TBranch *b_MC_MotherID;           //!
  TBranch *b_MC_BaryonN;            //!
  TBranch *b_MC_Mass;               //!
  TBranch *b_MC_Ptype;              //!
  TBranch *b_MC_Charge;             //!
  TBranch *b_MC_TOF;                //!
  TBranch *b_MC_Track_Length;       //!
  TBranch *b_MC_InitPos_x;          //!
  TBranch *b_MC_InitPos_y;          //!
  TBranch *b_MC_InitPos_z;          //!
  TBranch *b_MC_FinalPos_x;         //!
  TBranch *b_MC_FianlPos_y;         //!
  TBranch *b_MC_FinalPos_z;         //!
  TBranch *b_MC_InitMom_x;          //!
  TBranch *b_MC_InitMom_y;          //!
  TBranch *b_MC_InitMom_z;          //!
  TBranch *b_MC_FinalMom_x;         //!
  TBranch *b_MC_FinalMom_y;         //!
  TBranch *b_MC_FinalMom_z;         //!

  // constructor
  myAnalysis(TString filename = "Merge_12C_200_2023v2_1_ntu.root",
             TTree *tree = 0);

  virtual ~myAnalysis();

  virtual Int_t Cut(Long64_t entry);

  virtual Int_t GetEntry(Long64_t entry);

  virtual Long64_t LoadTree(Long64_t entry);

  virtual void Init(TTree *tree);

  virtual void PrepareLoop(Long64_t &init, Long64_t &nentries);

  virtual void setStyle();

  virtual void Analysis(Long64_t init, Long64_t nentries);

  virtual Bool_t Notify();

  virtual void Show(Long64_t entry = -1);

 private:
  virtual void BeforeLoop();
  virtual void AfterLoop();
  virtual void Loop(Long64_t init, Long64_t nentries);

  // total histo declaration fon analysis
  TH1D *h_A1;       // A_1
  TH1D *h_A2;       // A_2
  TH1D *h_A3;       // A_3
  TH1D *h_z_bethe;  // z_bethe
  TH1D *h_z_TW;     // z_TW
  TH2D *h_E_TOF;    // E_deposited vs TOF

  // histo declaration for A_i fragment reconstruction
  TH1D *h_A1r[6];  // A_1_r
  TH1D *h_A2r[6];  // A_2_r
  TH1D *h_A3r[6];  // A_3_r

  // histo declaration for other methods
  TH2D *histo_xy_clus;             // XY cluster distribution
  TH3D *histo_xyz_clus;            // XYZ cluster distribution
  TH3D *histo_xyz_trk_clus;        // XYZ cluster track distribution
  TH3D *histo_xyz_trk_clus_match;  // XYZ cluster track distribution match
  TH2D *histo_tw;                  // TW points distribution
  TH2D *histo_tw_matched;          // TW points distribution matched with vertex
  TH2D *histo_de_vs_tof;           // Energy released vs TOF distribution
  TH3D *histo_tw_3d;               // TW points in X,Y,Z
  TH3D *histo_vtxpoint;            // vtxpoint in X,Y,Z
};

#endif

#ifdef myAnalysis_cxx
myAnalysis::myAnalysis(TString filename, TTree *tree) : fChain(0) {
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile *)gROOT->GetListOfFiles()->FindObject(filename);
    if (!f || !f->IsOpen()) {
      f = new TFile(filename);
    }
    f->GetObject("OuTree", tree);
  }
  Init(tree);
}

myAnalysis::~myAnalysis() {
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t myAnalysis::GetEntry(Long64_t entry) {
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t myAnalysis::LoadTree(Long64_t entry) {
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void myAnalysis::Init(TTree *tree) {
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer
  vertex_x = 0;
  vertex_y = 0;
  vertex_z = 0;
  vt_trk_n = 0;
  vt_trk_chi2 = 0;
  vt_trk_slopez = 0;
  vt_trk_origin = 0;
  vt_trk_projTW = 0;
  vt_trk_clus_n = 0;
  trk_vtx_clus_MCId = 0;
  vt_trk_clus_tot_hits = 0;
  vt_trk_clus_x = 0;
  vt_trk_clus_y = 0;
  vt_trk_clus_z = 0;
  vt_clus_n = 0;
  vtx_clus_MCId = 0;
  vt_clus_tot_hits = 0;
  vt_clus_x = 0;
  vt_clus_y = 0;
  vt_clus_z = 0;
  vt_clus_MC = 0;
  msd_station_id = 0;
  msd_pt_n = 0;
  msd_pt_MCId = 0;
  msd_eloss1 = 0;
  msd_eloss2 = 0;
  msd_pos = 0;
  msd_station_clus_id = 0;
  msd_clus_n = 0;
  msd_clus_MCId = 0;
  msd_eloss = 0;
  msd_clus_pos = 0;
  TWChargePoint = 0;
  TATW_MCID_1 = 0;
  TATW_MCID_2 = 0;
  TWDe1Point = 0;
  TWDe2Point = 0;
  TWXPoint = 0;
  TWYPoint = 0;
  TWZPoint = 0;
  TWDeHit = 0;
  TW_MCID_hit = 0;
  TWTOFHit = 0;
  TWbarHit = 0;
  TWlayerHit = 0;
  TWTOF = 0;
  TWTOF1 = 0;
  TWTOF2 = 0;
  CAenergy = 0;
  CAposX = 0;
  CAposY = 0;
  CAposZ = 0;
  GLBtrackPx = 0;
  GLBtrackPy = 0;
  GLBtrackPz = 0;
  GLBtrackLength = 0;
  GLBtrackTWid = 0;
  GLBtrackCAid = 0;
  MC_Dead_region = 0;
  MC_Generation_region = 0;
  MC_FlukaID = 0;
  MC_MotherID = 0;
  MC_BaryonN = 0;
  MC_Mass = 0;
  MC_Ptype = 0;
  MC_Charge = 0;
  MC_TOF = 0;
  MC_Track_Length = 0;
  MC_InitPos_x = 0;
  MC_InitPos_y = 0;
  MC_InitPos_z = 0;
  MC_FinalPos_x = 0;
  MC_FianlPos_y = 0;
  MC_FinalPos_z = 0;
  MC_InitMom_x = 0;
  MC_InitMom_y = 0;
  MC_InitMom_z = 0;
  MC_FinalMom_x = 0;
  MC_FinalMom_y = 0;
  MC_FinalMom_z = 0;
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("ev", &ev, &b_ev);
  fChain->SetBranchAddress("vertex_n", &vertex_n, &b_vertex_n);
  fChain->SetBranchAddress("vertex_x", &vertex_x, &b_vertex_x);
  fChain->SetBranchAddress("vertex_y", &vertex_y, &b_vertex_y);
  fChain->SetBranchAddress("vertex_z", &vertex_z, &b_vertex_z);
  fChain->SetBranchAddress("vt_trk_n", &vt_trk_n, &b_vt_trk_n);
  fChain->SetBranchAddress("vt_trk_chi2", &vt_trk_chi2, &b_vt_trk_chi2);
  fChain->SetBranchAddress("vt_trk_slopez", &vt_trk_slopez, &b_vt_trk_slopez);
  fChain->SetBranchAddress("vt_trk_origin", &vt_trk_origin, &b_vt_trk_origin);
  fChain->SetBranchAddress("vt_trk_projTW", &vt_trk_projTW, &b_vt_trk_projTW);
  fChain->SetBranchAddress("vt_trk_clus_n", &vt_trk_clus_n, &b_vt_trk_clus_n);
  fChain->SetBranchAddress("trk_vtx_clus_MCId", &trk_vtx_clus_MCId,
                           &b_trk_vtx_clus_MCId);
  fChain->SetBranchAddress("vt_trk_clus_tot_hits", &vt_trk_clus_tot_hits,
                           &b_vt_trk_clus_tot_hits);
  fChain->SetBranchAddress("vt_trk_clus_x", &vt_trk_clus_x, &b_vt_trk_clus_x);
  fChain->SetBranchAddress("vt_trk_clus_y", &vt_trk_clus_y, &b_vt_trk_clus_y);
  fChain->SetBranchAddress("vt_trk_clus_z", &vt_trk_clus_z, &b_vt_trk_clus_z);
  fChain->SetBranchAddress("vt_clus_n", &vt_clus_n, &b_vt_clus_n);
  fChain->SetBranchAddress("vtx_clus_MCId", &vtx_clus_MCId, &b_vtx_clus_MCId);
  fChain->SetBranchAddress("vt_clus_tot_hits", &vt_clus_tot_hits,
                           &b_vt_clus_tot_hits);
  fChain->SetBranchAddress("vt_clus_x", &vt_clus_x, &b_vt_clus_x);
  fChain->SetBranchAddress("vt_clus_y", &vt_clus_y, &b_vt_clus_y);
  fChain->SetBranchAddress("vt_clus_z", &vt_clus_z, &b_vt_clus_z);
  fChain->SetBranchAddress("vt_clus_MC", &vt_clus_MC, &b_vt_clus_MC);
  fChain->SetBranchAddress("msd_station_id", &msd_station_id,
                           &b_msd_station_id);
  fChain->SetBranchAddress("msd_pt_n", &msd_pt_n, &b_msd_pt_n);
  fChain->SetBranchAddress("msd_pt_MCId", &msd_pt_MCId, &b_msd_pt_MCId);
  fChain->SetBranchAddress("msd_eloss1", &msd_eloss1, &b_msd_eloss1);
  fChain->SetBranchAddress("msd_eloss2", &msd_eloss2, &b_msd_eloss2);
  fChain->SetBranchAddress("msd_pos", &msd_pos, &b_msd_pos);
  fChain->SetBranchAddress("msd_station_clus_id", &msd_station_clus_id,
                           &b_msd_station_clus_id);
  fChain->SetBranchAddress("msd_clus_n", &msd_clus_n, &b_msd_clus_n);
  fChain->SetBranchAddress("msd_clus_MCId", &msd_clus_MCId, &b_msd_clus_MCId);
  fChain->SetBranchAddress("msd_eloss", &msd_eloss, &b_msd_eloss);
  fChain->SetBranchAddress("msd_clus_pos", &msd_clus_pos, &b_msd_clus_pos);
  fChain->SetBranchAddress("TWPoints", &TWPoints, &b_TWPoints);
  fChain->SetBranchAddress("TWChargePoint", &TWChargePoint, &b_TWChargePoint);
  fChain->SetBranchAddress("TATW_MCID_1", &TATW_MCID_1, &b_TATW_MCID_1);
  fChain->SetBranchAddress("TATW_MCID_2", &TATW_MCID_2, &b_TATW_MCID_2);
  fChain->SetBranchAddress("TWDe1Point", &TWDe1Point, &b_TWDe1Point);
  fChain->SetBranchAddress("TWDe2Point", &TWDe2Point, &b_TWDe2Point);
  fChain->SetBranchAddress("TWXPoint", &TWXPoint, &b_TWXPoint);
  fChain->SetBranchAddress("TWYPoint", &TWYPoint, &b_TWYPoint);
  fChain->SetBranchAddress("TWZPoint", &TWZPoint, &b_TWZPoint);
  fChain->SetBranchAddress("TWHit", &TWHit, &b_TWHit);
  fChain->SetBranchAddress("TWDeHit", &TWDeHit, &b_TWDeHit);
  fChain->SetBranchAddress("TW_MCID_hit", &TW_MCID_hit, &b_TW_MCID_hit);
  fChain->SetBranchAddress("TWTOFHit", &TWTOFHit, &b_TWTOFHit);
  fChain->SetBranchAddress("TWbarHit", &TWbarHit, &b_TWbarHit);
  fChain->SetBranchAddress("TWlayerHit", &TWlayerHit, &b_TWlayerHit);
  fChain->SetBranchAddress("TWTOF", &TWTOF, &b_TWTOF);
  fChain->SetBranchAddress("TWTOF1", &TWTOF1, &b_TWTOF1);
  fChain->SetBranchAddress("TWTOF2", &TWTOF2, &b_TWTOF2);
  fChain->SetBranchAddress("CAclusN", &CAclusN, &b_CAclusN);
  fChain->SetBranchAddress("CAenergy", &CAenergy, &b_CAenergy);
  fChain->SetBranchAddress("CAposX", &CAposX, &b_CAposX);
  fChain->SetBranchAddress("CAposY", &CAposY, &b_CAposY);
  fChain->SetBranchAddress("CAposZ", &CAposZ, &b_CAposZ);
  fChain->SetBranchAddress("GLBtracks", &GLBtracks, &b_GLBtracks);
  fChain->SetBranchAddress("GLBtrackPx", &GLBtrackPx, &b_GLBtrackPx);
  fChain->SetBranchAddress("GLBtrackPy", &GLBtrackPy, &b_GLBtrackPy);
  fChain->SetBranchAddress("GLBtrackPz", &GLBtrackPz, &b_GLBtrackPz);
  fChain->SetBranchAddress("GLBtrackLength", &GLBtrackLength,
                           &b_GLBtrackLength);
  fChain->SetBranchAddress("GLBtrackTWid", &GLBtrackTWid, &b_GLBtrackTWid);
  fChain->SetBranchAddress("GLBtrackCAid", &GLBtrackCAid, &b_GLBtrackCAid);
  fChain->SetBranchAddress("MC_Dead_region", &MC_Dead_region,
                           &b_MC_Dead_region);
  fChain->SetBranchAddress("MC_Generation_region", &MC_Generation_region,
                           &b_MC_Generation_region);
  fChain->SetBranchAddress("MC_FlukaID", &MC_FlukaID, &b_MC_FlukaID);
  fChain->SetBranchAddress("MC_MotherID", &MC_MotherID, &b_MC_MotherID);
  fChain->SetBranchAddress("MC_BaryonN", &MC_BaryonN, &b_MC_BaryonN);
  fChain->SetBranchAddress("MC_Mass", &MC_Mass, &b_MC_Mass);
  fChain->SetBranchAddress("MC_Ptype", &MC_Ptype, &b_MC_Ptype);
  fChain->SetBranchAddress("MC_Charge", &MC_Charge, &b_MC_Charge);
  fChain->SetBranchAddress("MC_TOF", &MC_TOF, &b_MC_TOF);
  fChain->SetBranchAddress("MC_Track_Length", &MC_Track_Length,
                           &b_MC_Track_Length);
  fChain->SetBranchAddress("MC_InitPos_x", &MC_InitPos_x, &b_MC_InitPos_x);
  fChain->SetBranchAddress("MC_InitPos_y", &MC_InitPos_y, &b_MC_InitPos_y);
  fChain->SetBranchAddress("MC_InitPos_z", &MC_InitPos_z, &b_MC_InitPos_z);
  fChain->SetBranchAddress("MC_FinalPos_x", &MC_FinalPos_x, &b_MC_FinalPos_x);
  fChain->SetBranchAddress("MC_FianlPos_y", &MC_FianlPos_y, &b_MC_FianlPos_y);
  fChain->SetBranchAddress("MC_FinalPos_z", &MC_FinalPos_z, &b_MC_FinalPos_z);
  fChain->SetBranchAddress("MC_InitMom_x", &MC_InitMom_x, &b_MC_InitMom_x);
  fChain->SetBranchAddress("MC_InitMom_y", &MC_InitMom_y, &b_MC_InitMom_y);
  fChain->SetBranchAddress("MC_InitMom_z", &MC_InitMom_z, &b_MC_InitMom_z);
  fChain->SetBranchAddress("MC_FinalMom_x", &MC_FinalMom_x, &b_MC_FinalMom_x);
  fChain->SetBranchAddress("MC_FinalMom_y", &MC_FinalMom_y, &b_MC_FinalMom_y);
  fChain->SetBranchAddress("MC_FinalMom_z", &MC_FinalMom_z, &b_MC_FinalMom_z);
  Notify();
}

Bool_t myAnalysis::Notify() {
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void myAnalysis::Show(Long64_t entry) {
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}

Int_t myAnalysis::Cut(Long64_t entry) {
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  return 1;
}

#endif  // #ifdef myAnalysis_cxx