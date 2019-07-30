#define IntensityScanMeasurements_cxx
#include "IntensityScanMeasurements.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TTreeReader.h>

#include <iostream>
using namespace std;

int run();
int run_loop(std::string path);

void IntensityScanMeasurements::Loop(){
    this->SetEnvironment();
    
    if (fChain == 0) return;
    
    Long64_t nentries = fChain->GetEntriesFast();
    Long64_t nbytes = 0, nb = 0;
    
    for(Long64_t jentry = 0; jentry < nentries; jentry++) {
        Long64_t ientry = this->LoadTree(jentry);
        
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
    
        this->SelectQ50VsIntensity();
        this->SelectQtVsIntensity();
        this->SelectVmaxVsIntensity();
        this->SelectFullWidthHalfHeightVsIntensity();
        this->SelectFullWidthHalfHeightVsVbias();
        this->SelectVoltageWaveforms();
    }
    
    this->Plot();
}

void IntensityScanMeasurements::SelectQ50VsIntensity(){
    switch ((int) Vbias) {
        case 300:
            graphs.at(0)->SetPoint(graphs.at(0)->GetN(), y, Q50);
            break;
            
        case 200:
            graphs.at(1)->SetPoint(graphs.at(1)->GetN(), y, Q50);
            break;
            
        case 100:
            graphs.at(2)->SetPoint(graphs.at(2)->GetN(), y, Q50);
            break;
            
        default:
            break;
    }
}

void IntensityScanMeasurements::SelectVmaxVsIntensity(){
    switch ((int) Vbias) {
        case 300:
            graphs.at(6)->SetPoint(graphs.at(6)->GetN(), y, Vmax);
            break;
            
        case 200:
            graphs.at(7)->SetPoint(graphs.at(7)->GetN(), y, Vmax);
            break;
            
        case 100:
            graphs.at(8)->SetPoint(graphs.at(8)->GetN(), y, Vmax);
            break;
            
        default:
            break;
    }
}

void IntensityScanMeasurements::SelectQtVsIntensity(){
//    for (int i = 0; i < Nt; i++) {
        switch ((int) Vbias) {
            case 300:
                graphs.at(3)->SetPoint(graphs.at(3)->GetN(), y, Qtot);
                break;
                
            case 200:
                graphs.at(4)->SetPoint(graphs.at(4)->GetN(), y, Qtot);
                break;
                
            case 100:
                graphs.at(5)->SetPoint(graphs.at(5)->GetN(), y, Qtot);
                break;
                
            default:
                break;
        }
//    }
}

void IntensityScanMeasurements::SelectFullWidthHalfHeightVsIntensity(){
        int index1 = this->GetHalfHeightPoint();
        int index2 = this->GetClosestNeighbor(index1);
        double timeDifference = abs(time[index2]-time[index1]);
    
        switch ((int) Vbias) {
            case 300:
                graphs.at(9)->SetPoint(graphs.at(9)->GetN(), y, timeDifference);
                break;
//
//            case 200:
//                graphs.at(10)->SetPoint(graphs.at(10)->GetN(), y, timeDifference);
//                break;
//
//            case 100:
//                graphs.at(11)->SetPoint(graphs.at(11)->GetN(), y, timeDifference);
//                break;
//
            default:
                break;
        }
}

void IntensityScanMeasurements::SelectFullWidthHalfHeightVsVbias(){
    int index1 = this->GetHalfHeightPoint();
    int index2 = this->GetClosestNeighbor(index1);
    double timeDifference = abs(time[index2]-time[index1]);
    
    switch ((int) y) {
        case 2800:
            graphs.at(12)->SetPoint(graphs.at(12)->GetN(), Vbias, timeDifference);
//            break;
//
//        case 2200:
//            graphs.at(13)->SetPoint(graphs.at(13)->GetN(), Vbias, timeDifference);
//            break;
//
//        case 1500:
//            graphs.at(14)->SetPoint(graphs.at(14)->GetN(), Vbias, timeDifference);
//            break;
            
        default:
            break;
    }
}

void IntensityScanMeasurements::SelectVoltageWaveforms(){
    if(y == 2800){
        for (int i = 0; i < Nt; i++) {
            switch ((int) Vbias) {
                case 350:
                    graphs.at(15)->SetPoint(graphs.at(15)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 325:
                    graphs.at(16)->SetPoint(graphs.at(16)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 300:
                    graphs.at(17)->SetPoint(graphs.at(17)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 275:
                    graphs.at(18)->SetPoint(graphs.at(18)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 250:
                    graphs.at(19)->SetPoint(graphs.at(19)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 225:
                    graphs.at(20)->SetPoint(graphs.at(20)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 200:
                    graphs.at(21)->SetPoint(graphs.at(21)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 175:
                    graphs.at(22)->SetPoint(graphs.at(22)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 150:
                    graphs.at(23)->SetPoint(graphs.at(23)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 125:
                    graphs.at(24)->SetPoint(graphs.at(24)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 100:
                    graphs.at(25)->SetPoint(graphs.at(25)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 75:
                    graphs.at(26)->SetPoint(graphs.at(26)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 50:
                    graphs.at(27)->SetPoint(graphs.at(27)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                case 25:
                    graphs.at(28)->SetPoint(graphs.at(28)->GetN(), time[i]-tleft, volt[i]-BlineMean);
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void IntensityScanMeasurements::SetEnvironment(){
    std::string graphName;
    
    this->SetStyle();
    
    canvases.push_back(new TCanvas("v_t_canvas_1", "Charge (50ns) vs VCSEL Intensity"));
    canvases.push_back(new TCanvas("v_t_canvas_2", "Charge (Total) vs VCSEL Intensity"));
    canvases.push_back(new TCanvas("v_t_canvas_3", "Vmax vs VCSEL Intensity"));
    canvases.push_back(new TCanvas("v_t_canvas_4", "Width (Half Max) vs Intensity"));
    canvases.push_back(new TCanvas("v_t_canvas_5", "Width (Half Max) vs Vbias"));
    canvases.push_back(new TCanvas("v_t_canvas_6", "Voltage vs Time"));
    
    for (int i = 0; i < 6; i++) {
        legends.push_back(new TLegend(0.1,0.7,0.48,0.9));
    }
    
    for (int i = 0; i < 29; i++) {
        graphs.push_back(new TGraph());
        graphName = "gr" + std::to_string(i);
        graphs.at(i)->SetName(graphName.data());
    }
}

void IntensityScanMeasurements::SetStyle(){
    gStyle->SetOptStat(0);
    gROOT->SetStyle("Plain"); /*Default white background for all plots*/
    
    gStyle->SetStripDecimals(kFALSE);
    
    /* set bkg color of all to 10: white, but not 0*/
    gStyle->SetCanvasColor(10);
    gStyle->SetFrameFillColor(10);
    gStyle->SetStatColor(10);
    gStyle->SetPadColor(10);
    gStyle->SetFillColor(10);
    gStyle->SetTitleFillColor(0);
    
    /* SetPaperSize wants width & height in cm: A4 is 20,26 & US is 20,24*/
    gStyle->SetPaperSize(20, 26);
    /* No yellow border around histogram*/
    gStyle->SetDrawBorder(0);
    /* remove border of canvas*/
    gStyle->SetCanvasBorderMode(0);
    /* remove border of pads*/
    gStyle->SetPadBorderMode(0);
    gStyle->SetFrameBorderMode(0);
    gStyle->SetLegendBorderSize(0);
    
    /* default text size*/
    gStyle->SetTextSize(0.05);
    gStyle->SetTitleSize(0.07,"xyz");
    gStyle->SetLabelSize(0.06,"xyz");
    /* title offset: distance between given text and axis, here x,y,z*/
    gStyle->SetLabelOffset(0.015,"xyz");
    gStyle->SetTitleOffset(1.,"yz");
    gStyle->SetTitleOffset(1.0,"x");
    
    /* Use visible font for all text*/
    int font = 42;
    gStyle->SetTitleFont(font);
    gStyle->SetTitleFontSize(0.06);
    gStyle->SetStatFont(font);
    gStyle->SetStatFontSize(0.07);
    gStyle->SetTextFont(font);
    gStyle->SetLabelFont(font,"xyz");
    gStyle->SetTitleFont(font,"xyz");
    gStyle->SetTitleBorderSize(0);
    gStyle->SetStatBorderSize(1);
    
    /* big marker points*/
    gStyle->SetMarkerStyle(1);
    gStyle->SetLineWidth(2);
    gStyle->SetMarkerSize(1.2);
    /*set palette in 2d histogram to nice and colorful one*/
    //gStyle->SetPalette(1,0);
    
    /*No title for histograms*/
    gStyle->SetOptTitle(0);
    /* show the errors on the stat box */
    gStyle->SetOptStat(0);
    /* show errors on fitted parameters*/
    gStyle->SetOptFit(0);
    /* number of decimals used for errors*/
    gStyle->SetEndErrorSize(5);
    
    /* set line width to 2 by default so that histograms are visible when printed small
     idea: emphasize the data, not the frame around*/
    gStyle->SetHistLineWidth(2);
    gStyle->SetFrameLineWidth(2);
    gStyle->SetFuncWidth(2);
    gStyle->SetHistLineColor(kBlack);
    gStyle->SetFuncColor(kRed);
    gStyle->SetLabelColor(kBlack,"xyz");
    
    //set the margins
    gStyle->SetPadBottomMargin(0.18);
    gStyle->SetPadTopMargin(0.08);
    gStyle->SetPadRightMargin(0.08);
    gStyle->SetPadLeftMargin(0.2);
    
    //set the number of divisions to show
    gStyle->SetNdivisions(506, "xy");
    
    //turn off xy grids
    gStyle->SetPadGridX(0);
    gStyle->SetPadGridY(0);
    
    //set the tick mark style
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    
    gStyle->SetCanvasDefW(800);
    gStyle->SetCanvasDefH(700);
    
    gROOT->ForceStyle();
    
    gStyle->SetOptStat(0);
}

void IntensityScanMeasurements::Plot(){
    canvases.at(0)->cd();
    graphs.at(0)->SetTitle("Z3415W16TS (VCSEL Intensity Scan, 1064nm)");
    graphs.at(0)->GetXaxis()->SetTitle("VCSEL Drive Pulse [mV]");
    graphs.at(0)->GetYaxis()->SetTitle("Charge (50ns) [C]");
    graphs.at(0)->SetLineColor(1);
    graphs.at(0)->Draw();
    graphs.at(1)->SetLineColor(2);
    graphs.at(1)->Draw("same");
    graphs.at(2)->SetLineColor(3);
    graphs.at(2)->Draw("same");
    legends.at(0)->SetHeader("Vbias","C");
    legends.at(0)->AddEntry("gr0","300V","l");
    legends.at(0)->AddEntry("gr1","200V","l");
    legends.at(0)->AddEntry("gr2","100V","l");
    legends.at(0)->Draw();
    
    canvases.at(1)->cd();
    graphs.at(3)->SetTitle("Z3415W16TS (VCSEL Intensity Scan, 1064nm)");
    graphs.at(3)->GetXaxis()->SetTitle("VCSEL Drive Pulse [mV]");
    graphs.at(3)->GetYaxis()->SetTitle("Charge (Total) [C]");
    graphs.at(3)->SetLineColor(1);
    graphs.at(3)->Draw();
    graphs.at(4)->SetLineColor(2);
    graphs.at(4)->Draw("same");
    graphs.at(5)->SetLineColor(3);
    graphs.at(5)->Draw("same");
    legends.at(1)->SetHeader("Vbias","C");
    legends.at(1)->AddEntry("gr3","300V","l");
    legends.at(1)->AddEntry("gr4","200V","l");
    legends.at(1)->AddEntry("gr5","100V","l");
    legends.at(1)->Draw();
    
    canvases.at(2)->cd();
    graphs.at(6)->SetTitle("Z3415W16TS (VCSEL Intensity Scan, 1064nm)");
    graphs.at(6)->GetXaxis()->SetTitle("VCSEL Drive Pulse [mV]");
    graphs.at(6)->GetYaxis()->SetTitle("Vmax [mV]");
    graphs.at(6)->SetLineColor(1);
    graphs.at(6)->Draw();
    graphs.at(7)->SetLineColor(2);
    graphs.at(7)->Draw("same");
    graphs.at(8)->SetLineColor(3);
    graphs.at(8)->Draw("same");
    legends.at(2)->SetHeader("Vbias","C");
    legends.at(2)->AddEntry("gr6","300V","l");
    legends.at(2)->AddEntry("gr7","200V","l");
    legends.at(2)->AddEntry("gr8","100V","l");
    legends.at(2)->Draw();
    
    canvases.at(3)->cd();
    graphs.at(9)->SetTitle("Z3415W16TS (VCSEL Intensity Scan, 1064nm, Vbias == 300V)");
    graphs.at(9)->GetXaxis()->SetTitle("VCSEL Drive Pulse [mV]");
    graphs.at(9)->GetYaxis()->SetTitle("Width (Half Max) [ns]");
    graphs.at(9)->SetLineColor(1);
    graphs.at(9)->Draw();
//    graphs.at(10)->SetLineColor(2);
//    graphs.at(10)->Draw("same");
//    graphs.at(11)->SetLineColor(3);
//    graphs.at(11)->Draw("same");
    
    canvases.at(4)->cd();
    graphs.at(12)->SetTitle("Z3415W16TS (VCSEL Intensity Scan, 1064nm, y == 2800)");
    graphs.at(12)->GetXaxis()->SetTitle("Vbias [V]");
    graphs.at(12)->GetYaxis()->SetTitle("Width (Half Max) [ns]");
    graphs.at(12)->SetLineColor(1);
    graphs.at(12)->Draw();
//    graphs.at(13)->SetLineColor(2);
//    graphs.at(13)->Draw("same");
//    graphs.at(14)->SetLineColor(3);
//    graphs.at(14)->Draw("same");
    
    canvases.at(5)->cd();
    graphs.at(15)->SetTitle("Z3415W16TS (VCSEL Intensity Scan, 1064nm)");
    graphs.at(15)->GetXaxis()->SetTitle("Voltage [V]");
    graphs.at(15)->GetYaxis()->SetTitle("Time [ns]");
    graphs.at(15)->SetLineColor(1);
    graphs.at(15)->Draw();
    
    for(unsigned int i = 2; i <= 14; i++){
        graphs.at(i+14)->SetLineColor(i);
        graphs.at(i+14)->Draw("same");
    }
    
//    graphs.at(16)->SetLineColor(2);
//    graphs.at(16)->Draw("same");
//    graphs.at(17)->SetLineColor(3);
//    graphs.at(17)->Draw("same");
//    graphs.at(18)->SetLineColor(4);
//    graphs.at(18)->Draw("same");
//    graphs.at(19)->SetLineColor(5);
//    graphs.at(19)->Draw("same");
//    graphs.at(20)->SetLineColor(6);
//    graphs.at(20)->Draw("same");
//    graphs.at(21)->SetLineColor(7);
//    graphs.at(21)->Draw("same");
//    graphs.at(22)->SetLineColor(8);
//    graphs.at(22)->Draw("same");
//    graphs.at(23)->SetLineColor(9);
//    graphs.at(23)->Draw("same");
//    graphs.at(24)->SetLineColor(10);
//    graphs.at(24)->Draw("same");
//    graphs.at(25)->SetLineColor(11);
//    graphs.at(25)->Draw("same");
//    graphs.at(26)->SetLineColor(12);
//    graphs.at(26)->Draw("same");
//    graphs.at(27)->SetLineColor(13);
//    graphs.at(27)->Draw("same");
//    graphs.at(28)->SetLineColor(14);
//    graphs.at(28)->Draw("same");
    legends.at(5)->SetHeader("Vbias","C");
    legends.at(5)->AddEntry("gr15", "350V","l");
    legends.at(5)->AddEntry("gr16", "325V","l");
    legends.at(5)->AddEntry("gr17", "300V","l");
    legends.at(5)->AddEntry("gr18", "275V","l");
    legends.at(5)->AddEntry("gr19", "250V","l");
    legends.at(5)->AddEntry("gr20", "225V","l");
    legends.at(5)->AddEntry("gr21", "200V","l");
    legends.at(5)->AddEntry("gr22", "175V","l");
    legends.at(5)->AddEntry("gr23", "150V","l");
    legends.at(5)->AddEntry("gr24", "125V","l");
    legends.at(5)->AddEntry("gr25", "100V","l");
    legends.at(5)->AddEntry("gr26", "75V","l");
    legends.at(5)->AddEntry("gr27", "50V","l");
    legends.at(5)->AddEntry("gr28", "25V","l");
    legends.at(5)->Draw();
}

int IntensityScanMeasurements::IsHalfHeight(double height){
    double half_height = (Vmax - Vmin)/2;
    double tolerance = 0.005;
    return this->WithinRange(half_height, height, tolerance);
}

int IntensityScanMeasurements::WithinRange(double a, double b, double tolerance){
    
    double top_limit = a * (1.0 + tolerance);
    double lower_limit = a * (1.0 - tolerance);
    
    if(top_limit >= b && b >= lower_limit){
        return 1;
    }
    
    return 0;
}

int IntensityScanMeasurements::GetHalfHeightPoint(){
    double half_height = (Vmax - Vmin)/2;
    double difference = 0;
    int halfHeightPoint = 0;
    
    for (int i = 0; i < Nt; i++) {
            if(difference == 0 || difference > abs(half_height - volt[i])){
                difference = abs(half_height - volt[i]);
                halfHeightPoint = i;
            }
    }
    
    return halfHeightPoint;
}

int IntensityScanMeasurements::GetClosestNeighbor(int index){
    int closestNeighbor = 0, index2 = 0;
    double difference = 0;
    
    for (int i = 0; i < Nt; i++) {
        if(abs(time[i] - time[index]) > 1.0){
            if(difference == 0 || difference > abs(volt[index] - volt[i])){
                difference = abs(volt[index] - volt[i]);
                closestNeighbor = i;
            }
        }
    }
    return closestNeighbor;
}

int run(){
    std::string sensor1 = "Z3415W16TS";
    std::string sensor2 = "Z3415W9TS";
    std::string sensor3 = "Z5471W1TS";
    
    std::string path1 = sensor1 + "/2019-07-04_17-07-23_Z3415W16TS.txt.root";
    std::string path2 = sensor1 + "/VCSEL_Z3415W16TS.txt.root";
    std::string path3 = "Z3415W16TS/2019-07-04_17-04-10_Z3415W16TS.txt.root";
    std::string path4 = sensor1 + "/2019-07-04_17-13-51_Z3415W16TS.txt.root";
    std::string path5 = "VCSEL_IntensityScan_Z3415W16TS.txt.root";
    
    std::string path6 = sensor2 + "/2019-07-04_17-31-35_Z3415W9TS.txt.root";
    
    std::string path7 = sensor3 + "/2019-07-04_17-42-17_Z5471W1TS.txt.root";
    std::string path8 = sensor3 + "/2019-07-04_17-46-23_Z5471W1TS.txt.root";
    std::string path9 = sensor3 + "/2019-07-04_17-46-23_Z5471W1TS.txt.root";
    
    run_loop(path5);
    
    return 0;
}

int run_loop(std::string path){
    TFile* f1 = new TFile(path.data(), "READ");
    TTree* tree = (TTree*)f1->Get("edge");
    
    IntensityScanMeasurements m(tree);
//    m.Init(tree);
    
    m.Loop();
    
    delete tree;
    delete f1;
    return 0;
}



