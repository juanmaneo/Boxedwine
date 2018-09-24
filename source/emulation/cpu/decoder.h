#ifndef __CPU_DECODER_H__
#define __CPU_DECODER_H__

#define eaa1(cpu, op) cpu->seg[op->base].address + (U16)(cpu->reg[op->rm].u16 + (S16)cpu->reg[op->sibIndex].u16 + op->disp)
#define eaa3(cpu, op) cpu->seg[op->base].address + cpu->reg[op->rm].u32 + (cpu->reg[op->sibIndex].u32 << + op->sibScale) + op->disp
#define eaa(cpu, op) (op->ea16)?(eaa1(cpu, op)):(eaa3(cpu, op))

#define CF		0x00000001
#define PF		0x00000004
#define AF		0x00000010
#define ZF		0x00000040
#define SF		0x00000080
#define DF		0x00000400
#define OF		0x00000800

#define TF		0x00000100
#define IF		0x00000200

#define IOPL	0x00003000
#define NT		0x00004000
#define VM		0x00020000
#define AC		0x00040000
#define ID		0x00200000

// Flags might be set or they might remain untouched
#define MAYBE 0x80000000

#define regAX 0
#define regCX 1
#define regDX 2
#define regBX 3
#define regSP 4
#define regBP 5
#define regSI 6
#define regDI 7
#define regZero 8

enum Instruction {
    AddR8E8 = 0,
    AddE8R8,
    AddR8R8,
    AddR8I8,
    AddE8I8,
    AddR16E16,
    AddE16R16,
    AddR16R16,
    AddR16I16,
    AddE16I16,
    AddR32E32,
    AddE32R32,
    AddR32R32,
    AddR32I32,
    AddE32I32,

    OrR8E8,
    OrE8R8,
    OrR8R8,
    OrR8I8,
    OrE8I8,
    OrR16E16,
    OrE16R16,
    OrR16R16,
    OrR16I16,
    OrE16I16,
    OrR32E32,
    OrE32R32,
    OrR32R32,
    OrR32I32,
    OrE32I32,

    AdcR8E8,
    AdcE8R8,
    AdcR8R8,
    AdcR8I8,
    AdcE8I8,
    AdcR16E16,
    AdcE16R16,
    AdcR16R16,
    AdcR16I16,
    AdcE16I16,
    AdcR32E32,
    AdcE32R32,
    AdcR32R32,
    AdcR32I32,
    AdcE32I32,

    SbbR8E8,
    SbbE8R8,
    SbbR8R8,
    SbbR8I8,
    SbbE8I8,
    SbbR16E16,
    SbbE16R16,
    SbbR16R16,
    SbbR16I16,
    SbbE16I16,
    SbbR32E32,
    SbbE32R32,
    SbbR32R32,
    SbbR32I32,
    SbbE32I32,

    AndR8E8,
    AndE8R8,
    AndR8R8,
    AndR8I8,
    AndE8I8,
    AndR16E16,
    AndE16R16,
    AndR16R16,
    AndR16I16,
    AndE16I16,
    AndR32E32,
    AndE32R32,
    AndR32R32,
    AndR32I32,
    AndE32I32,

    SubR8E8,
    SubE8R8,
    SubR8R8,
    SubR8I8,
    SubE8I8,
    SubR16E16,
    SubE16R16,
    SubR16R16,
    SubR16I16,
    SubE16I16,
    SubR32E32,
    SubE32R32,
    SubR32R32,
    SubR32I32,
    SubE32I32,

    XorR8E8,
    XorE8R8,
    XorR8R8,
    XorR8I8,
    XorE8I8,
    XorR16E16,
    XorE16R16,
    XorR16R16,
    XorR16I16,
    XorE16I16,
    XorR32E32,
    XorE32R32,
    XorR32R32,
    XorR32I32,
    XorE32I32,

    CmpR8E8,
    CmpE8R8,
    CmpR8R8,
    CmpR8I8,
    CmpE8I8,
    CmpR16E16,
    CmpE16R16,
    CmpR16R16,
    CmpR16I16,
    CmpE16I16,
    CmpR32E32,
    CmpE32R32,
    CmpR32R32,
    CmpR32I32,
    CmpE32I32,

    TestE8R8,
    TestR8R8,
    TestR8I8,
    TestE8I8,
    TestE16R16,
    TestR16R16,
    TestR16I16,
    TestE16I16,
    TestE32R32,
    TestR32R32,
    TestR32I32,
    TestE32I32,

    NotR8, 
    NotE8,
    NotR16, 
    NotE16,
    NotR32, 
    NotE32,

    NegR8, 
    NegE8,
    NegR16, 
    NegE16,
    NegR32, 
    NegE32,

    MulR8, 
    MulE8,
    MulR16, 
    MulE16,
    MulR32, 
    MulE32,

    IMulR8, 
    IMulE8,
    IMulR16, 
    IMulE16,
    IMulR32, 
    IMulE32,

    DivR8, 
    DivE8,
    DivR16, 
    DivE16,
    DivR32, 
    DivE32,

    IDivR8, 
    IDivE8,
    IDivR16, 
    IDivE16,
    IDivR32, 
    IDivE32,

    XchgR8R8, 
    XchgE8R8,
    XchgR16R16, 
    XchgE16R16,
    XchgR32R32, 
    XchgE32R32,

    BtR16R16,
    BtE16R16,
    BtR32R32,
    BtE32R32,

    BtsR16R16,
    BtsE16R16,
    BtsR32R32,
    BtsE32R32,

    BtrR16R16, 
    BtrE16R16,
    BtrR32R32, 
    BtrE32R32,

    BsfR16R16, 
    BsfR16E16,
    BsfR32R32, 
    BsfR32E32,

    BsrR16R16, 
    BsrR16E16,
    BsrR32R32, 
    BsrR32E32,

    BtcR16R16,
    BtcE16R16,
    BtcR32R32,
    BtcE32R32,

    BtR16, 
    BtE16,
    BtsR16, 
    BtsE16,
    BtrR16, 
    BtrE16,
    BtcR16, 
    BtcE16,

    BtR32, 
    BtE32,
    BtsR32, 
    BtsE32,
    BtrR32, 
    BtrE32,
    BtcR32, 
    BtcE32,

    DshlR16R16,
    DshlE16R16,
    DshlClR16R16,
    DshlClE16R16,
    DshrR16R16,
    DshrE16R16,
    DshrClR16R16,
    DshrClE16R16,

    DshlR32R32,
    DshlE32R32,
    DshlClR32R32,
    DshlClE32R32,
    DshrR32R32,
    DshrE32R32,
    DshrClR32R32,
    DshrClE32R32,

    DimulR16R16,
    DimulR16E16,
    DimulR32R32,
    DimulR32E32,

    CmpXchgR16R16, 
    CmpXchgE16R16,
    CmpXchgR32R32, 
    CmpXchgE32R32,

    IncR8,
    IncR16,
    IncR32,
    IncE8,
    IncE16,
    IncE32,

    DecR8,
    DecR16,
    DecR32,
    DecE8,
    DecE16,
    DecE32,

    PushSeg16,
    PopSeg16,
    PushSeg32,
    PopSeg32,

    PushR16,
    PushR32,
    PushE16,
    PushE32,

    PopR16,
    PopR32,
    PopE16,
    PopE32,

    PushA16,
    PushA32,
    PopA16,
    PopA32,

    Push16,
    Push32,

    PushF16,
    PushF32,
    PopF16,
    PopF32,

    Bound16,
    Bound32,

    ArplReg, 
    ArplMem,
    ArplReg32, 
    ArplMem32,

    Daa,
    Das,
    Aaa,
    Aas,
    Aam,
    Aad,

    ImulR16E16,
    ImulR16R16,
    ImulR32E32,
    ImulR32R32,

    Insb,
    Insw,
    Insd,

    Outsb,
    Outsw,
    Outsd,

    JumpO,
    JumpNO,
    JumpB,
    JumpNB,
    JumpZ,
    JumpNZ,
    JumpBE,
    JumpNBE,
    JumpS,
    JumpNS,
    JumpP,
    JumpNP,
    JumpL,
    JumpNL,
    JumpLE,
    JumpNLE,

    MovR8R8, 
    MovE8R8,
    MovR8E8,
    MovR8I8,
    MovE8I8,
    MovR16R16, 
    MovE16R16,
    MovR16E16,
    MovR16I16,
    MovE16I16,
    MovR32R32, 
    MovE32R32,
    MovR32E32,
    MovR32I32,
    MovE32I32,

    MovR16S16, 
    MovR32S16,
    MovE16S16,
    MovS16R16,
    MovS16E16,

    MovAlOb,
    MovAxOw,
    MovEaxOd,
    MovObAl,
    MovOwAx,
    MovOdEax,

    MovGwXzR8,
    MovGwXzE8,
    MovGwSxR8,
    MovGwSxE8,

    MovGdXzR8,
    MovGdXzE8,
    MovGdSxR8,
    MovGdSxE8,

    MovGdXzR16,
    MovGdXzE16,
    MovGdSxR16,
    MovGdSxE16,

    LeaR16,
    LeaR32,

    Nop,
    Cwd,
    Cwq,
    CallAp,
    CallFar,
    JmpAp,
    JmpFar,
    Wait,
    Sahf,
    Lahf,
    Salc,
    Retn16Iw,
    Retn32Iw,
    Retn16,
    Retn32,
    Retf16,
    Retf32,
    Invalid, 
    Int3,
    Int80,
    Int98,
    Int99,
    IntIb,
    IntO,
    Iret,
    Iret32,
    Xlat, 
    ICEBP, 
    Hlt,
    Cmc,
    Clc,
    Stc,
    Cli,
    Sti,
    Cld,
    Std,
    Rdtsc,
    CPUID,

    Enter16,
    Enter32,
    Leave16,
    Leave32,
    
    LoadSegment16,
    LoadSegment32,

    Movsb,
    Movsw,
    Movsd,
    Cmpsb,
    Cmpsw,
    Cmpsd,
    Stosb,
    Stosw,
    Stosd,
    Lodsb,
    Lodsw,
    Lodsd,
    Scasb,
    Scasw,
    Scasd,

    RolR8I8, 
    RolE8I8,
    RorR8I8, 
    RorE8I8,
    RclR8I8, 
    RclE8I8,
    RcrR8I8, 
    RcrE8I8,
    ShlR8I8, 
    ShlE8I8,
    ShrR8I8, 
    ShrE8I8,
    SarR8I8, 
    SarE8I8,

    RolR16I8, 
    RolE16I8,
    RorR16I8, 
    RorE16I8,
    RclR16I8, 
    RclE16I8,
    RcrR16I8, 
    RcrE16I8,
    ShlR16I8, 
    ShlE16I8,
    ShrR16I8, 
    ShrE16I8,
    SarR16I8, 
    SarE16I8,

    RolR32I8, 
    RolE32I8,
    RorR32I8, 
    RorE32I8,
    RclR32I8, 
    RclE32I8,
    RcrR32I8, 
    RcrE32I8,
    ShlR32I8, 
    ShlE32I8,
    ShrR32I8, 
    ShrE32I8,
    SarR32I8, 
    SarE32I8,

    RolR8Cl, 
    RolE8Cl,
    RorR8Cl, 
    RorE8Cl,
    RclR8Cl, 
    RclE8Cl,
    RcrR8Cl, 
    RcrE8Cl,
    ShlR8Cl, 
    ShlE8Cl,
    ShrR8Cl, 
    ShrE8Cl,
    SarR8Cl, 
    SarE8Cl,

    RolR16Cl, 
    RolE16Cl,
    RorR16Cl, 
    RorE16Cl,
    RclR16Cl, 
    RclE16Cl,
    RcrR16Cl, 
    RcrE16Cl,
    ShlR16Cl, 
    ShlE16Cl,
    ShrR16Cl, 
    ShrE16Cl,
    SarR16Cl, 
    SarE16Cl,

    RolR32Cl, 
    RolE32Cl,
    RorR32Cl, 
    RorE32Cl,
    RclR32Cl, 
    RclE32Cl,
    RcrR32Cl, 
    RcrE32Cl,
    ShlR32Cl, 
    ShlE32Cl,
    ShrR32Cl, 
    ShrE32Cl,
    SarR32Cl, 
    SarE32Cl,

    FADD_ST0_STj,
    FMUL_ST0_STj,
    FCOM_STi,
    FCOM_STi_Pop,
    FSUB_ST0_STj,
    FSUBR_ST0_STj,
    FDIV_ST0_STj,
    FDIVR_ST0_STj,
    FADD_SINGLE_REAL,
    FMUL_SINGLE_REAL,
    FCOM_SINGLE_REAL,
    FCOM_SINGLE_REAL_Pop,
    FSUB_SINGLE_REAL,
    FSUBR_SINGLE_REAL,
    FDIV_SINGLE_REAL,
    FDIVR_SINGLE_REAL,

    FLD_STi,
    FXCH_STi,
    FNOP,
    FST_STi_Pop,
    FCHS,
    FABS,
    FTST,
    FXAM,
    FLD1,
    FLDL2T,
    FLDL2E,
    FLDPI,
    FLDLG2,
    FLDLN2,
    FLDZ,
    F2XM1,
    FYL2X,
    FPTAN,
    FPATAN,
    FXTRACT,
    FPREM_nearest,
    FDECSTP,
    FINCSTP,
    FPREM,
    FYL2XP1,
    FSQRT,
    FSINCOS,
    FRNDINT,
    FSCALE,
    FSIN,
    FCOS,
    FLD_SINGLE_REAL,
    FST_SINGLE_REAL,
    FST_SINGLE_REAL_Pop,
    FLDENV,
    FLDCW,
    FNSTENV,
    FNSTCW,

    FCMOV_ST0_STj_CF,
    FCMOV_ST0_STj_ZF,
    FCMOV_ST0_STj_CF_OR_ZF,
    FCMOV_ST0_STj_PF,
    FUCOMPP,
    FIADD_DWORD_INTEGER,
    FIMUL_DWORD_INTEGER,
    FICOM_DWORD_INTEGER,
    FICOM_DWORD_INTEGER_Pop,
    FISUB_DWORD_INTEGER,
    FISUBR_DWORD_INTEGER,
    FIDIV_DWORD_INTEGER,
    FIDIVR_DWORD_INTEGER,

    FCMOV_ST0_STj_NCF,
    FCMOV_ST0_STj_NZF,
    FCMOV_ST0_STj_NCF_AND_NZF,
    FCMOV_ST0_STj_NPF,
    FNCLEX,
    FNINIT,
    FUCOMI_ST0_STj,
    FCOMI_ST0_STj_Pop,
    FILD_DWORD_INTEGER,
    FISTTP32,
    FIST_DWORD_INTEGER,
    FIST_DWORD_INTEGER_Pop,
    FLD_EXTENDED_REAL,
    FSTP_EXTENDED_REAL,

    FADD_STi_ST0,
    FMUL_STi_ST0,
    FSUBR_STi_ST0,
    FSUB_STi_ST0,
    FDIVR_STi_ST0,
    FDIV_STi_ST0,
    FADD_DOUBLE_REAL,
    FMUL_DOUBLE_REAL,
    FCOM_DOUBLE_REAL,
    FCOM_DOUBLE_REAL_Pop,
    FSUB_DOUBLE_REAL,
    FSUBR_DOUBLE_REAL,
    FDIV_DOUBLE_REAL,
    FDIVR_DOUBLE_REAL,

    FFREE_STi,
    FST_STi,
    FUCOM_STi,
    FUCOM_STi_Pop,
    FLD_DOUBLE_REAL,
    FISTTP64,
    FST_DOUBLE_REAL,
    FST_DOUBLE_REAL_Pop,
    FRSTOR,
    FNSAVE,
    FNSTSW,

    FADD_STi_ST0_Pop,
    FMUL_STi_ST0_Pop,
    FCOMPP,
    FSUBR_STi_ST0_Pop,
    FSUB_STi_ST0_Pop,
    FDIVR_STi_ST0_Pop,
    FDIV_STi_ST0_Pop,
    FIADD_WORD_INTEGER,
    FIMUL_WORD_INTEGER,
    FICOM_WORD_INTEGER,
    FICOM_WORD_INTEGER_Pop,
    FISUB_WORD_INTEGER,
    FISUBR_WORD_INTEGER,
    FIDIV_WORD_INTEGER,
    FIDIVR_WORD_INTEGER,

    FFREEP_STi,
    FNSTSW_AX,
    FUCOMI_ST0_STj_Pop,
    FILD_WORD_INTEGER,
    FISTTP16,
    FIST_WORD_INTEGER,
    FIST_WORD_INTEGER_Pop,
    FBLD_PACKED_BCD,
    FILD_QWORD_INTEGER,
    FBSTP_PACKED_BCD,
    FISTP_QWORD_INTEGER,

    LoopNZ,
    LoopZ,
    Loop,
    Jcxz,

    InAlIb,
    InAxIb,
    InEaxIb,
    OutIbAl,
    OutIbAx,
    OutIbEax,
    InAlDx,
    InAxDx,
    InEaxDx,
    OutDxAl,
    OutDxAx,
    OutDxEax,

    CallJw,
    CallJd,
    JmpJw,
    JmpJd,
    JmpJb,
    CallR16, 
    CallR32, 
    CallE16,
    CallE32,
    CallFarE16,
    CallFarE32,
    JmpR16, 
    JmpR32, 
    JmpE16,
    JmpE32,
    JmpFarE16,
    JmpFarE32,

    LarR16R16,
    LarR16E16,
    LslR16R16,
    LslR16E16,

    CmovO_R16R16, 
    CmovO_R16E16,
    CmovNO_R16R16, 
    CmovNO_R16E16,
    CmovB_R16R16, 
    CmovB_R16E16,
    CmovNB_R16R16, 
    CmovNB_R16E16,
    CmovZ_R16R16, 
    CmovZ_R16E16,
    CmovNZ_R16R16, 
    CmovNZ_R16E16,
    CmovBE_R16R16, 
    CmovBE_R16E16,
    CmovNBE_R16R16, 
    CmovNBE_R16E16,
    CmovS_R16R16, 
    CmovS_R16E16,
    CmovNS_R16R16, 
    CmovNS_R16E16,
    CmovP_R16R16, 
    CmovP_R16E16,
    CmovNP_R16R16, 
    CmovNP_R16E16,
    CmovL_R16R16, 
    CmovL_R16E16,
    CmovNL_R16R16, 
    CmovNL_R16E16,
    CmovLE_R16R16, 
    CmovLE_R16E16,
    CmovNLE_R16R16, 
    CmovNLE_R16E16,

    CmovO_R32R32, 
    CmovO_R32E32,
    CmovNO_R32R32, 
    CmovNO_R32E32,
    CmovB_R32R32, 
    CmovB_R32E32,
    CmovNB_R32R32, 
    CmovNB_R32E32,
    CmovZ_R32R32, 
    CmovZ_R32E32,
    CmovNZ_R32R32, 
    CmovNZ_R32E32,
    CmovBE_R32R32, 
    CmovBE_R32E32,
    CmovNBE_R32R32, 
    CmovNBE_R32E32,
    CmovS_R32R32, 
    CmovS_R32E32,
    CmovNS_R32R32, 
    CmovNS_R32E32,
    CmovP_R32R32, 
    CmovP_R32E32,
    CmovNP_R32R32, 
    CmovNP_R32E32,
    CmovL_R32R32, 
    CmovL_R32E32,
    CmovNL_R32R32, 
    CmovNL_R32E32,
    CmovLE_R32R32, 
    CmovLE_R32E32,
    CmovNLE_R32R32, 
    CmovNLE_R32E32,

    SetO_R8, 
    SetO_E8,
    SetNO_R8, 
    SetNO_E8,
    SetB_R8, 
    SetB_E8,
    SetNB_R8, 
    SetNB_E8,
    SetZ_R8, 
    SetZ_E8,
    SetNZ_R8, 
    SetNZ_E8,
    SetBE_R8, 
    SetBE_E8,
    SetNBE_R8, 
    SetNBE_E8,
    SetS_R8, 
    SetS_E8,
    SetNS_R8, 
    SetNS_E8,
    SetP_R8, 
    SetP_E8,
    SetNP_R8, 
    SetNP_E8,
    SetL_R8, 
    SetL_E8,
    SetNL_R8, 
    SetNL_E8,
    SetLE_R8, 
    SetLE_E8,
    SetNLE_R8, 
    SetNLE_E8,

    SLDTReg, 
    SLDTE16,
    STRReg, 
    STRE16,
    LLDTR16, 
    LLDTE16,
    LTRR16, 
    LTRE16,
    VERRR16, 
    VERRE16,
    VERWR16, 
    VERWE16,

    SGDT,
    SIDT,
    LGDT,
    LIDT,
    SMSWRreg, 
    SMSW,
    LMSWRreg, 
    LMSW,
    INVLPG,

    XaddR32R32, 
    XaddR32E32,
    CmpXchg8b,
    Bswap32,

    PunpcklbwMmx, 
    PunpcklbwE64,
    PunpcklwdMmx, 
    PunpcklwdE64,
    PunpckldqMmx, 
    PunpckldqE64,
    PacksswbMmx, 
    PacksswbE64,
    PcmpgtbMmx, 
    PcmpgtbE64,
    PcmpgtwMmx, 
    PcmpgtwE64,
    PcmpgtdMmx, 
    PcmpgtdE64,
    PackuswbMmx, 
    PackuswbE64,
    PunpckhbwMmx, 
    PunpckhbwE64,
    PunpckhwdMmx, 
    PunpckhwdE64,
    PunpckhdqMmx, 
    PunpckhdqE64,
    PackssdwMmx, 
    PackssdwE64,
    MovPqR32, 
    MovPqE32,
    MovPqMmx, 
    MovPqE64,
    Psrlw, 
    Psraw, 
    Psllw,
    Psrld, 
    Psrad, 
    Pslld,
    Psrlq, 
    Psllq,
    PcmpeqbMmx, 
    PcmpeqbE64,
    PcmpeqwMmx, 
    PcmpeqwE64,
    PcmpeqdMmx, 
    PcmpeqdE64,
    Emms,
    MovR32Pq, 
    MovE32Pq,
    MovMmxPq, 
    MovE64Pq,
    PsrlwMmx, 
    PsrlwE64,
    PsrldMmx, 
    PsrldE64,
    PsrlqMmx, 
    PsrlqE64,
    PmullwMmx, 
    PmullwE64,
    PsubusbMmx, 
    PsubusbE64,
    PsubuswMmx, 
    PsubuswE64,
    PandMmx, 
    PandE64,
    PaddusbMmx, 
    PaddusbE64,
    PadduswMmx, 
    PadduswE64,
    PandnMmx, 
    PandnE64,
    PsrawMmx, 
    PsrawE64,
    PsradMmx, 
    PsradE64,
    PmulhwMmx, 
    PmulhwE64,
    PsubsbMmx, 
    PsubsbE64,
    PsubswMmx, 
    PsubswE64,
    PorMmx, 
    PorE64,
    PaddsbMmx, 
    PaddsbE64,
    PaddswMmx, 
    PaddswE64,
    PxorMmx, 
    PxorE64,
    PsllwMmx, 
    PsllwE64,
    PslldMmx, 
    PslldE64,
    PsllqMmx, 
    PsllqE64,
    PmaddwdMmx, 
    PmaddwdE64,
    PsubbMmx, 
    PsubbE64,
    PsubwMmx, 
    PsubwE64,
    PsubdMmx, 
    PsubdE64,
    PaddbMmx, 
    PaddbE64,
    PaddwMmx, 
    PaddwE64,
    PadddMmx, 
    PadddE64,

    Callback,
    Done,
    Custom1,
    InstructionCount
};

#define NUMBER_OF_OPS 915

#define ES 0
#define CS 1
#define SS 2
#define DS 3
#define FS 4
#define GS 5

class InstructionInfo {
public:    
    U32  branch;
    U32  readMemWidth;
    U32  writeMemWidth;    
    U32 flagsSets;
    U32 flagsUsed;
    U32 flagsUndefined;
    U32 throwsException;
};

extern const InstructionInfo instructionInfo[];

class DecodedOp;

typedef void (OPCALL *OpCallback)(CPU* cpu, DecodedOp* op);

class DecodedOp {
public:    
    static DecodedOp* alloc();
    void dealloc(bool deallocNext);    
    void log(CPU* cpu);
    bool needsToSetFlags();

    DecodedOp* next;
    OpCallback pfn;

    U32 disp;

    U32 imm;

#ifdef _DEBUG
    U16 originalOp;    
    Instruction inst;
#else
    U16 inst;
#endif
    U8 reg;
    U8 rm;        

    U8 base;
    U8 sibIndex;	
    U8 sibScale;    
    U8 len; // guaranteed to be 15 bytes or less

    U8 lock;
    U8 repZero;
    U8 repNotZero;    
    U8 ea16;
private:
    void init();
};

class DecodedBlock;

typedef U8 (*pfnFetchByte)(U32* pEip);

class DecodedBlockFromNode {
public:
    static DecodedBlockFromNode* alloc();
    virtual void dealloc();

    DecodedBlock* block;
    DecodedBlockFromNode* next;
};

class DecodedBlock {
public:   
    static DecodedBlock* currentBlock;

    DecodedOp* op;
    U32 opCount;
    U32 bytes;
    U32 runCount;

    DecodedBlock* next1;
    DecodedBlock* next2;    

    virtual void run(CPU* cpu) = 0;
    virtual void dealloc(bool delayed) = 0;

    void addReferenceFrom(DecodedBlock* block);
    void removeReferenceFrom(DecodedBlock* block);
protected:
    DecodedBlockFromNode* referencedFrom;
};
void decodeBlock(pfnFetchByte fetchByte, U32 eip, U32 isBig, U32 maxInstructions, U32 maxLen, U32 stopIfThrowsException, DecodedBlock* block);

#endif