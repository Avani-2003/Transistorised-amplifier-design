#include <stdio.h>
float vdd, R2, R1, vth = 0.7, vds, vgs, ids, k = 0.000025, gm;
void ckt(float R1, float R2, float VDD)
{
    printf("                VDD=%.2f", VDD);
    printf("\n         _______|_____");
    printf("\n         |           |");
    printf("\n         |           |");
    printf("\n         <           <");
    printf("\n R1=%.2f>        Rd >", R1);
    printf("\n         <           <       CC2");
    printf("\n         |           |-------|(-----*Vo");
    printf("\n         |           |");
    printf("\n    CC1  |         |--");
    printf("\n ---)|------------||--");
    printf("\n |       |         |->");
    printf("\n |       |           |");
    printf("\n |       |           |----------");
    printf("\n |       |           |         |");
    printf("\n @       <           <         |");
    printf("\n |R2=%.1f>        Rs >        ---Cs", R2);
    printf("\n |       <           <        ---");
    printf("\n |       |           |         |");
    printf("\n |_______|___________|_________|");
    printf("\n       __|__       __|__ ");
    printf("\n        ---         ---   ");
    printf("\n         -           -");
    printf("\n");
    printf("\n");
}
void cutoff()
{
    printf("\n Vgs<Vthreshold\nChannel Cant be created, hence \nIds=0");
}
void sat()
{
    //float vdd, R2, R1, vth = 0.7, vdssat, vgs, ids, k = 0.000025, gm;
    float vdssat;
    printf("\nEnter Value of VDD:");
    scanf("%f", &vdd);
    printf("\nNOTE: R2>R1");
    printf("\nEnter R1:");
    scanf("%f", &R1);
    printf("\nEnter R2:");
    scanf("%f", &R2);
    vgs = vdd * (R2 / (R2 + R1));
    printf("\nMOSFET in Saturation Region");
    printf("\nVth=%f", vth);

    vdssat = vgs - vth;
    ids = k * (vdssat * vdssat);
    gm = ids / vgs;
    ids = ids * 1000000;
    printf("\nVgs=%f Volts", vgs);
    printf("\nVds(sat)=%f Volts", vdssat);
    printf("\nIds=%f MicroAmperes", ids);
    printf("\nTransconductance gain Gm=%f", gm);
    printf("\n\n\n");
    ckt(R1, R2, vdd);
}
void linear()
{
    //float vdd, R2, R1, vth = 0.7, vds, vgs, ids, k = 0.000025, gm;
    printf("\nEnter Value of VDD:");
    scanf("%f", &vdd);
    printf("\nNOTE: R2>R1");
    printf("\nEnter R1:");
    scanf("%f", &R1);
    printf("\nEnter R2:");
    scanf("%f", &R2);
    vgs = vdd * (R2 / (R2 + R1));
    printf("\nMOSFET in Linear Region");
    printf("\nVth=%f", vth);

    vds = vgs - vth;
    ids = k * vds * (vgs - (vds / 2) - vth);
    gm = ids / vgs;
    ids = ids * 1000000;

    printf("\nVgs=%f Volts", vgs);
    printf("\nVds>%f Volts", vds);
    printf("\nIds=%f Micro Amperes", ids);
    printf("\nTransconductance gain Gm=%f", gm);
    printf("\n\n\n");
    ckt(R1, R2, vdd);
}

void cs(){
    float rd,Vo;
    //float vdd, R2, R1, vth = 0.7, vds, vgs, ids, k = 0.000025, gm;
    vdd=10;
    printf("\nNOTE: R2>R1");
    printf("\nEnter R1:");
    scanf("%f", &R1);
    printf("\nEnter R2:");
    scanf("%f", &R2);
    printf("\nEnter Value of Rd:");
    scanf("%f",&rd);
    vgs = vdd * (R2 / (R2 + R1));
    ids = vdd/(2*rd);
    Vo=vdd-(ids*rd);

    printf("\nVgs=%0.3f, Ids=%0.3f, Vout=%0.3f", vgs, ids, Vo);
    gm=k*(vgs-vth);
    float av;
    av=-gm*rd;
    printf("Gm=%0.3f, Av=%0.3f", gm,av);
   // printf("\nMOSFET in Linear Region");
    printf("\nVth=%f", vth);
}

void cd(){
    //float vdd, R2, R1, vth = 0.7, vds, vgs, ids, k = 0.000025, gm;
    printf("\nAssumptions Made:\nWe assume that NMOS operates in Saturation Region and Ignore the Channel Length Modulation");
    sat();
}
void mosfet()
{
    printf("N-MOSFET CHARACTERISTICS CALCULATOR\n");
    printf("\n");
    printf("Select Region of operation/configurations:\n1. Cutoff\n2. Saturation\n3. Linear\n4. Common Source\n5. Common Drain\n");
    int ch1;
    printf("\nEnter Choice:");
    scanf("%d", &ch1);
    switch (ch1)
    {
    case 1: cutoff(); break;
    case 2: sat(); break;
    case 3: linear(); break;
    case 4: cs();break;
    case 5: cd();break;
    default: break;
    }
}
float VB = 0.7; // base to emitter voltage
void circuit(float vcc, float rb, float b, float rc)
{
    printf("\n\n");
    printf("\n                           --:: CIRCUIT DIAGRAM FOR FIXED-BIAS CONFIGURATION OF BJT ::--");
    printf("\n");
    printf("\n                                            Vcc == %.2f", vcc);
    printf("\n                                               o");
    printf("\n                                               |");
    printf("\n                                               |");
    printf("\n                        _______________________|");
    printf("\n                        |                      |");
    printf("\n                        |                      |");
    printf("\n                        >                      >");
    printf("\n                        <                      <");
    printf("\n                        < Rb                   < Rc = %.2f", rc);
    printf("\n                        > %.2f                 >", rb);
    printf("\n                        <                      |");
    printf("\n                        |                      |               C2");
    printf("\n                        |                      |_______________| |__________o OUT");
    printf("\n                        |                      |               | |");
    printf("\n                        |                      |");
    printf("\n           C1           |                 Q1   /");
    printf("\no__________| |__________|____________________|/  B = %.2f ", b);
    printf("\n           | |                               |\\");
    printf("\n                                              \\/");
    printf("\n                                               |");
    printf("\n                                               |");
    printf("\n                                               |");
    printf("\n                                               |");
    printf("\n                                               |");
    printf("\n                                             __|__");
    printf("\n                                              ---");
    printf("\n                                               -");
}
void formula_list1()
{
	printf("\n\n\n");
    printf("Formula List for BJT :- \n\n");
    printf("1) Base Current :- \n\n");
    printf("        VCC - VBE");
    printf("\n IB = --------------");
    printf("\n            RB\n\n");
    printf("2) Collector Current :- \n");
    printf("\n IC = B.IB\n\n");
    printf("3) Collector to Emitter Voltage :- \n");
    printf("\n VCE = VCC - IC.RC\n\n");
    printf("4) Saturation Current :- \n\n");
    printf("         VCC");
    printf("\n ICsat = ----");
    printf("\n          RC");
    printf("\n========================================\n");
}
void fixed_bias(int VCC)
{
    float RB, IB, B, IC, RC, VCE, ICsat;
    // to find base current
    printf("Given - \n VCC = %.2f Volts \n VB = %.2f Volts", VCC, VB);
    printf("\nEnter the Value of Base Resistance(RB in Kohm): ");
    scanf("%f", &RB);
    IB = (VCC - VB) / (RB * 1000);
    printf("\nBase Current : %f uA", IB * 1000000);
    printf("\n--------------------------------------------");
    // to find collector current
    printf("\nEnter the Value of B(Beta): ");
    scanf("%f", &B);
    IC = IB * B;
    printf("\nCollector Current : %f mA", IC * 1000);
    printf("\n--------------------------------------------");
    // to find collector to emitter voltage
    printf("\nEnter the Value of Collector Resistance(RC in Kohm): ");
    scanf("%f", &RC);
    VCE = VCC - (IC * RC);
    printf("\nCollector to Emitter Voltage : %f Volt", VCE);
    printf("\n--------------------------------------------");
    // to find saturation current
    ICsat = VCC / RC;
    printf("\nSaturation Current : %f mA", ICsat);
    printf("\n--------------------------------------------");
    circuit(VCC, RB, B, RC);
    printf("\n\n\n");
}
void formula_list2()
{
	printf("\n\n\n");
	printf("\n-: EMITTER BIASED CONFIGURATION OF BJT :-\n");
    printf("Formula List for BJT :- \n\n");
    printf("1) Base Current :- \n\n");
    printf("        VCC - VBE");
    printf("\n IB = --------------");
    printf("\n       RB +(B+1)RE\n\n");
    printf("2) Collector to Emitter Voltage :- \n");
    printf("\n VCE = VCC - IC(RC+RE)\n\n");
    printf("3) Saturation Current :- \n\n");
    printf("          VCC");
    printf("\n ICsat = ------");
    printf("\n          RC+RE");
    printf("\n========================================\n");
}
void emitter_bias(int VCC)
{
	float RE,RC,RB,B,IB,IC,VCE,ICsat;
	printf("\nEnter the Value of Emitter Resistance(RE in Kohm) : ");
    scanf("%f", &RE);
    printf("\nEnter the Value of Collector Resistance(RC in Kohm): ");
    scanf("%f", &RC);
    printf("\nEnter the Value of Base Resistance(RB in Kohm): ");
    scanf("%f", &RB);
    printf("\nEnter the Value of B(Beta): ");
    scanf("%f", &B);
	IB = (VCC - VB)/(RB+(B+1)*RE*1000);
	printf("\nBase Current : %f mA", IB * 1000);
    printf("\n--------------------------------------------");
    IC = IB * B;
	VCE = VCC - IC*(RC+RE);
	printf("\nCollector to Emitter Voltage : %.2f Volt", VCE);
    printf("\n--------------------------------------------");
	ICsat = VCC/(RC+RE);
	printf("\nSaturation Current : %f mA", ICsat);
    printf("\n--------------------------------------------");
}
void formula_list3()
{
	printf("\n\n\n");
	printf("\n-: COLLECTOR FEEDBACK CONFIGURATION OF BJT :-\n");
    printf("Formula List for BJT :- \n\n");
    printf("1) Base Current :- \n\n");
    printf("        VCC - VBE");
    printf("\n IB = --------------");
    printf("\n       RF + B(RC + RE)\n\n");
    printf("2) Collector Current :- \n");
    printf("\n IC = B.IB\n\n");
    printf("2) Emitter Current :- \n");
    printf("\n IC = (B+1).IB\n\n");
    printf("4) Collector to Emitter Voltage :- \n");
    printf("\n VCE = VCC - IC(RC+RE)\n\n");
    printf("\n========================================\n");
}
void Collector_fb(int VCC)
{ 
    float RF,RC,RE,B,IB,IC,IE,VCE;
    printf("\nEnter the Value of Feedback Resistance(RF in Kohm): ");
    scanf("%f", &RF);
    printf("\nEnter the Value of Emitter Resistance(RE in Kohm) : ");
    scanf("%f", &RE);
    printf("\nEnter the Value of Collector Resistance(RC in Kohm): ");
    scanf("%f", &RC);
    IB = (VCC - VB) / RF + B*(RC+RE);
    printf("\nBase Current : %f uA", IB * 1000000);
    printf("\n--------------------------------------------");
    IC = IB * B;
    printf("\nCollector Current : %f mA", IC * 1000);
    printf("\n--------------------------------------------");
    IE = (B+1)*IB;
    printf("\nCollector Current : %f mA", IE * 1000);
    printf("\n--------------------------------------------");
    VCE = VCC - IC*(RC+RE);
	printf("\nCollector to Emitter Voltage : %.2f Volt", VCE);
	printf("\n--------------------------------------------");
}
void formula_list4()
{
	printf("\n\n\n");
	printf("\n-: COMMON BASE CONFIGURATION OF BJT :-\n");
    printf("Formula List for BJT :- \n\n");
    printf("1) Emitter Current :- \n\n");
    printf("        VCC - VBE");
    printf("\n IE = --------------");
    printf("\n            RE\n\n");
    printf("2) Base Current :- \n");
    printf("        IE");
    printf("\n IB = ----");
    printf("\n       B+1");
    printf("\n3) Collector Current :- \n");
    printf("\n IC = B.IB\n\n");
    printf("4) Collector to Emitter Voltage :- \n");
    printf("\n VCE = VEE + VEE - IE(RC+RE)\n\n");
    printf("4) Collector to Base Voltage :- \n");
    printf("\n VCB = VCC - IC.RC\n\n");
    printf("\n========================================\n");
}
void common_base(int VCC)
{
	float VEE=-10,RE,IE,B,IC,IB,RC,VCE,VCB;
	// to find base current
    printf("Given - \n VCC = %d Volts \n VB = %.2f Volts\n VEE = %.2f", VCC, VB,VEE);
    printf("\nEnter the Value of Emitter Resistance(RE in Kohm): ");
    scanf("%f", &RE);
    IE = (VEE - VB)/RE;
    printf("\nEmitter Current : %f uA", IE * 1000000);
    printf("\n--------------------------------------------");
    // to find collector current
    printf("\nEnter the Value of B(Beta): ");
    scanf("%f", &B);
    IB = IE/(B+1);
    printf("\nBase Current : %f mA", IB * 1000);
    printf("\n--------------------------------------------");
    IC = IB * B;
    printf("\nCollector Current : %f mA", IC * 1000);
    printf("\n--------------------------------------------");
    // to find collector to emitter voltage
    printf("\nEnter the Value of Collector Resistance(RC in Kohm): ");
    scanf("%f", &RC);
    VCE = VEE + VCC - IE*(RC + RE);
    printf("\nCollector to Emitter Voltage : %f Volt", VCE);
    printf("\n--------------------------------------------");
    VCB = VCC - (IC * RC);
    printf("\nCollector to Base Voltage : %f Volt", VCB);
    printf("\n--------------------------------------------");
	
}
int bjt()
{
    int VCC=10;
    printf("BJT CHARACTERISTICS CALCULATOR\n");
    printf("\n");
    printf("Select Region of operation/configurations:\n1. Fixed biased \n2. Emitter biased\n3. Collector feedback\n4. Common Base\n");
    int ch1;
    printf("\nEnter Choice:");
    scanf("%d", &ch1);
    switch (ch1)
    {
    case 1: formula_list1();
            fixed_bias(VCC);
	        break;
    case 2: formula_list2();
            emitter_bias(VCC);
	        break;
    case 3: formula_list3();
            Collector_fb(VCC);
	        break;
    case 4: formula_list4();
            common_base(VCC);
	        break;
    default: break;
    return 0;
	}
}
int main()
{
    int choice=1;
    while (choice==1)
    {
    	printf("Which Transistorised Amplifier you want choose???\n");
        printf("\n1. MOSFET\n2. BJT");
        printf("\nEnter Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: mosfet(); break;
        case 2: bjt(); break;
        case 3: printf("Exit"); break;
        }
        printf("\nDo you want to continue.");
        printf("\n1.Yes\n2.No");
        printf("\nEnter Choice:");
        scanf("%d",&choice);
  }
}

