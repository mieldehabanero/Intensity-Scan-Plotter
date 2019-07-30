//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul 22 16:47:36 2019 by ROOT version 6.18/00
// from TTree edge/eTCT measurement
// found on file: VCSEL_IntensityScan_Z3415W16TS.txt.root
//////////////////////////////////////////////////////////

#ifndef IntensityScanMeasurements_h
#define IntensityScanMeasurements_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>
#include <TGraph.h>
#include <TLegend.h>

// Header file for the classes stored in the TTree if any.

class IntensityScanMeasurements {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
 //TMeas           *raw;
   Double_t        Ax;
   Double_t        Ay;
   Double_t        Az;
   TDatime         utc;
   UInt_t          event;
   Double_t        Itot;
   Double_t        x;
   Double_t        y;
   Double_t        z;
   Int_t           ix;
   Int_t           iy;
   Int_t           iz;
   Double_t        Temp;
   Double_t        Vbias;
   Double_t        pWidth;
   Double_t        pAmpl;
   Int_t           Nt;
   Double_t        volt[8000];   //[Nt]
   Double_t        time[8000];   //[Nt]
   Double_t        Qt[8000];   //[Nt]
 //TWaveform       *proc;
   Double_t        LPower;
   Double_t        LNph;
   Double_t        Vmax;
   Double_t        Vmin;
   Int_t           iVmax;
   Int_t           iVmin;
   Double_t        tVmax;
   Double_t        tVmin;
   Double_t        tleft;
   Double_t        tright;
   Double_t        trms;
   Double_t        aVmax;
   Double_t        aVmin;
   Int_t           aiVmax;
   Int_t           aiVmin;
   Double_t        tcoll[9];
   Double_t        t1st;
   Int_t           it1st;
   Double_t        tder;
   Double_t        itder;
   Double_t        toa[21];
   Double_t        atcfd[19];
   Double_t        aitcfd[19];
   Double_t        athcfd[19];
   Double_t        aslewth[19];
   Double_t        aslewth_cfd[19];
   Double_t        cfdval[19];
   Int_t           aNdelay[19];
   Double_t        tcfd[19];
   Double_t        itcfd[19];
   Double_t        thcfd[19];
   Double_t        slewth[19];
   Double_t        slewth_cfd[19];
   Int_t           itleft;
   Int_t           itright;
   Int_t           aitleft;
   Int_t           aitright;
   Double_t        BlineMean;
   Double_t        BlineRMS;
   Double_t        aBlineMean;
   Double_t        aBlineRMS;
   Double_t        BlineMeanTcoll;
   Double_t        BlineRMSTcoll;
   Double_t        atleft;
   Double_t        atright;
   Double_t        at1st;
   Int_t           ait1st;
   Double_t        Q50;
   Double_t        Qtot;
   Double_t        cct;
   Double_t        acct;
   Double_t        RiseTime;

   // List of branches
   TBranch        *b_raw_Ax;   //!
   TBranch        *b_raw_Ay;   //!
   TBranch        *b_raw_Az;   //!
   TBranch        *b_raw_utc;   //!
   TBranch        *b_raw_event;   //!
   TBranch        *b_raw_Itot;   //!
   TBranch        *b_raw_x;   //!
   TBranch        *b_raw_y;   //!
   TBranch        *b_raw_z;   //!
   TBranch        *b_raw_ix;   //!
   TBranch        *b_raw_iy;   //!
   TBranch        *b_raw_iz;   //!
   TBranch        *b_raw_Temp;   //!
   TBranch        *b_raw_Vbias;   //!
   TBranch        *b_raw_pWidth;   //!
   TBranch        *b_raw_pAmpl;   //!
   TBranch        *b_raw_Nt;   //!
   TBranch        *b_volt;   //!
   TBranch        *b_time;   //!
   TBranch        *b_Qt;   //!
   TBranch        *b_proc_LPower;   //!
   TBranch        *b_proc_LNph;   //!
   TBranch        *b_proc_Vmax;   //!
   TBranch        *b_proc_Vmin;   //!
   TBranch        *b_proc_iVmax;   //!
   TBranch        *b_proc_iVmin;   //!
   TBranch        *b_proc_tVmax;   //!
   TBranch        *b_proc_tVmin;   //!
   TBranch        *b_proc_tleft;   //!
   TBranch        *b_proc_tright;   //!
   TBranch        *b_proc_trms;   //!
   TBranch        *b_proc_aVmax;   //!
   TBranch        *b_proc_aVmin;   //!
   TBranch        *b_proc_aiVmax;   //!
   TBranch        *b_proc_aiVmin;   //!
   TBranch        *b_proc_tcoll;   //!
   TBranch        *b_proc_t1st;   //!
   TBranch        *b_proc_it1st;   //!
   TBranch        *b_proc_tder;   //!
   TBranch        *b_proc_itder;   //!
   TBranch        *b_proc_toa;   //!
   TBranch        *b_proc_atcfd;   //!
   TBranch        *b_proc_aitcfd;   //!
   TBranch        *b_proc_athcfd;   //!
   TBranch        *b_proc_aslewth;   //!
   TBranch        *b_proc_aslewth_cfd;   //!
   TBranch        *b_proc_cfdval;   //!
   TBranch        *b_proc_aNdelay;   //!
   TBranch        *b_proc_tcfd;   //!
   TBranch        *b_proc_itcfd;   //!
   TBranch        *b_proc_thcfd;   //!
   TBranch        *b_proc_slewth;   //!
   TBranch        *b_proc_slewth_cfd;   //!
   TBranch        *b_proc_itleft;   //!
   TBranch        *b_proc_itright;   //!
   TBranch        *b_proc_aitleft;   //!
   TBranch        *b_proc_aitright;   //!
   TBranch        *b_proc_BlineMean;   //!
   TBranch        *b_proc_BlineRMS;   //!
   TBranch        *b_proc_aBlineMean;   //!
   TBranch        *b_proc_aBlineRMS;   //!
   TBranch        *b_proc_BlineMeanTcoll;   //!
   TBranch        *b_proc_BlineRMSTcoll;   //!
   TBranch        *b_proc_atleft;   //!
   TBranch        *b_proc_atright;   //!
   TBranch        *b_proc_at1st;   //!
   TBranch        *b_proc_ait1st;   //!
   TBranch        *b_proc_Q50;   //!
   TBranch        *b_proc_Qtot;   //!
   TBranch        *b_proc_cct;   //!
   TBranch        *b_proc_acct;   //!
   TBranch        *b_proc_RiseTime;   //!

   IntensityScanMeasurements(TTree *tree=0);
   virtual ~IntensityScanMeasurements();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
    
//    Mine
    std::vector<TCanvas*> canvases;
    std::vector<TGraph*> graphs;
    std::vector<TLegend*> legends;
    std::vector<int> halfHeightMeasurements;
    
    void           SetEnvironment();
    void           SetStyle();
    void           Plot();
    virtual int    WithinRange(double a, double b, double range);
    virtual int    IsHalfHeight(double height);
    void           SelectQ50VsIntensity();
    void           SelectVmaxVsIntensity();
    void           SelectQtVsIntensity();
    int            GetHalfHeightPoint();
    void           SelectFullWidth();
    void           SelectFullWidthHalfHeightVsIntensity();
    void           SelectFullWidthHalfHeightVsVbias();
    void           SelectVoltageWaveforms();
    int            GetClosestNeighbor(int index);
};

#endif

#ifdef IntensityScanMeasurements_cxx
IntensityScanMeasurements::IntensityScanMeasurements(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("VCSEL_IntensityScan_Z3415W16TS.txt.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("VCSEL_IntensityScan_Z3415W16TS.txt.root");
      }
      f->GetObject("edge",tree);

   }
   Init(tree);
}

IntensityScanMeasurements::~IntensityScanMeasurements()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t IntensityScanMeasurements::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t IntensityScanMeasurements::LoadTree(Long64_t entry)
{
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

void IntensityScanMeasurements::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Ax", &Ax, &b_raw_Ax);
   fChain->SetBranchAddress("Ay", &Ay, &b_raw_Ay);
   fChain->SetBranchAddress("Az", &Az, &b_raw_Az);
   fChain->SetBranchAddress("utc", &utc, &b_raw_utc);
   fChain->SetBranchAddress("event", &event, &b_raw_event);
   fChain->SetBranchAddress("Itot", &Itot, &b_raw_Itot);
   fChain->SetBranchAddress("x", &x, &b_raw_x);
   fChain->SetBranchAddress("y", &y, &b_raw_y);
   fChain->SetBranchAddress("z", &z, &b_raw_z);
   fChain->SetBranchAddress("ix", &ix, &b_raw_ix);
   fChain->SetBranchAddress("iy", &iy, &b_raw_iy);
   fChain->SetBranchAddress("iz", &iz, &b_raw_iz);
   fChain->SetBranchAddress("Temp", &Temp, &b_raw_Temp);
   fChain->SetBranchAddress("Vbias", &Vbias, &b_raw_Vbias);
   fChain->SetBranchAddress("pWidth", &pWidth, &b_raw_pWidth);
   fChain->SetBranchAddress("pAmpl", &pAmpl, &b_raw_pAmpl);
   fChain->SetBranchAddress("Nt", &Nt, &b_raw_Nt);
   fChain->SetBranchAddress("volt", volt, &b_volt);
   fChain->SetBranchAddress("time", time, &b_time);
   fChain->SetBranchAddress("Qt", Qt, &b_Qt);
   fChain->SetBranchAddress("LPower", &LPower, &b_proc_LPower);
   fChain->SetBranchAddress("LNph", &LNph, &b_proc_LNph);
   fChain->SetBranchAddress("Vmax", &Vmax, &b_proc_Vmax);
   fChain->SetBranchAddress("Vmin", &Vmin, &b_proc_Vmin);
   fChain->SetBranchAddress("iVmax", &iVmax, &b_proc_iVmax);
   fChain->SetBranchAddress("iVmin", &iVmin, &b_proc_iVmin);
   fChain->SetBranchAddress("tVmax", &tVmax, &b_proc_tVmax);
   fChain->SetBranchAddress("tVmin", &tVmin, &b_proc_tVmin);
   fChain->SetBranchAddress("tleft", &tleft, &b_proc_tleft);
   fChain->SetBranchAddress("tright", &tright, &b_proc_tright);
   fChain->SetBranchAddress("trms", &trms, &b_proc_trms);
   fChain->SetBranchAddress("aVmax", &aVmax, &b_proc_aVmax);
   fChain->SetBranchAddress("aVmin", &aVmin, &b_proc_aVmin);
   fChain->SetBranchAddress("aiVmax", &aiVmax, &b_proc_aiVmax);
   fChain->SetBranchAddress("aiVmin", &aiVmin, &b_proc_aiVmin);
   fChain->SetBranchAddress("tcoll[9]", tcoll, &b_proc_tcoll);
   fChain->SetBranchAddress("t1st", &t1st, &b_proc_t1st);
   fChain->SetBranchAddress("it1st", &it1st, &b_proc_it1st);
   fChain->SetBranchAddress("tder", &tder, &b_proc_tder);
   fChain->SetBranchAddress("itder", &itder, &b_proc_itder);
   fChain->SetBranchAddress("toa[21]", toa, &b_proc_toa);
   fChain->SetBranchAddress("atcfd[19]", atcfd, &b_proc_atcfd);
   fChain->SetBranchAddress("aitcfd[19]", aitcfd, &b_proc_aitcfd);
   fChain->SetBranchAddress("athcfd[19]", athcfd, &b_proc_athcfd);
   fChain->SetBranchAddress("aslewth[19]", aslewth, &b_proc_aslewth);
   fChain->SetBranchAddress("aslewth_cfd[19]", aslewth_cfd, &b_proc_aslewth_cfd);
   fChain->SetBranchAddress("cfdval[19]", cfdval, &b_proc_cfdval);
   fChain->SetBranchAddress("aNdelay[19]", aNdelay, &b_proc_aNdelay);
   fChain->SetBranchAddress("tcfd[19]", tcfd, &b_proc_tcfd);
   fChain->SetBranchAddress("itcfd[19]", itcfd, &b_proc_itcfd);
   fChain->SetBranchAddress("thcfd[19]", thcfd, &b_proc_thcfd);
   fChain->SetBranchAddress("slewth[19]", slewth, &b_proc_slewth);
   fChain->SetBranchAddress("slewth_cfd[19]", slewth_cfd, &b_proc_slewth_cfd);
   fChain->SetBranchAddress("itleft", &itleft, &b_proc_itleft);
   fChain->SetBranchAddress("itright", &itright, &b_proc_itright);
   fChain->SetBranchAddress("aitleft", &aitleft, &b_proc_aitleft);
   fChain->SetBranchAddress("aitright", &aitright, &b_proc_aitright);
   fChain->SetBranchAddress("BlineMean", &BlineMean, &b_proc_BlineMean);
   fChain->SetBranchAddress("BlineRMS", &BlineRMS, &b_proc_BlineRMS);
   fChain->SetBranchAddress("aBlineMean", &aBlineMean, &b_proc_aBlineMean);
   fChain->SetBranchAddress("aBlineRMS", &aBlineRMS, &b_proc_aBlineRMS);
   fChain->SetBranchAddress("BlineMeanTcoll", &BlineMeanTcoll, &b_proc_BlineMeanTcoll);
   fChain->SetBranchAddress("BlineRMSTcoll", &BlineRMSTcoll, &b_proc_BlineRMSTcoll);
   fChain->SetBranchAddress("atleft", &atleft, &b_proc_atleft);
   fChain->SetBranchAddress("atright", &atright, &b_proc_atright);
   fChain->SetBranchAddress("at1st", &at1st, &b_proc_at1st);
   fChain->SetBranchAddress("ait1st", &ait1st, &b_proc_ait1st);
   fChain->SetBranchAddress("Q50", &Q50, &b_proc_Q50);
   fChain->SetBranchAddress("Qtot", &Qtot, &b_proc_Qtot);
   fChain->SetBranchAddress("cct", &cct, &b_proc_cct);
   fChain->SetBranchAddress("acct", &acct, &b_proc_acct);
   fChain->SetBranchAddress("RiseTime", &RiseTime, &b_proc_RiseTime);
   Notify();
}

Bool_t IntensityScanMeasurements::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void IntensityScanMeasurements::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

#endif // #ifdef IntensityScanMeasurements_cxx
