void OPCALL dynamic_pushEw_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_push16, false, false, false, 2, 0, DYN_PARAM_CPU, offsetof(CPU, reg[op->reg].u16), DYN_PARAM_CPU_ADDRESS_16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popEw_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_pop16, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushEw_mem(CPU* cpu, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    movFromMem(DYN_16bit, DYN_ADDRESS);
    callHostFunction(common_push16, false, false, false, 2, 0, DYN_PARAM_CPU, DYN_READ_RESULT, DYN_PARAM_REG_16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popEw_mem(CPU* cpu, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    callHostFunction(common_pop16, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushEd_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_push32, false, false, false, 2, 0, DYN_PARAM_CPU, offsetof(CPU, reg[op->reg].u32), DYN_PARAM_CPU_ADDRESS_32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popEd_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_pop32, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushEd_mem(CPU* cpu, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    movFromMem(DYN_32bit, DYN_ADDRESS);
    callHostFunction(common_push32, false, false, false, 2, 0, DYN_PARAM_CPU, DYN_READ_RESULT, DYN_PARAM_REG_32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popEd_mem(CPU* cpu, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    callHostFunction(common_pop32, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushSeg16(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_push16, false, false, false, 2, 0, DYN_PARAM_CPU, offsetof(CPU, seg[op->reg].value), DYN_PARAM_CPU_ADDRESS_16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popSeg16(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_peek16, true, false, false, 2, 0, DYN_PARAM_CPU, 0, DYN_PARAM_CONST_32);
    callHostFunction(common_setSegment, true, false, true, 3, 0, DYN_PARAM_CPU, op->reg, DYN_PARAM_CONST_32, DYN_CALL_RESULT, DYN_PARAM_REG_32);
    if (cpu->stackMask==0xFFFFFFFF) {
        movToRegFromCpu(DYN_SRC, offsetof(CPU, reg[4].u32), DYN_32bit);
        instRegImm('+', DYN_SRC, DYN_32bit, 2);
        movToCpuFromReg(offsetof(CPU, reg[4].u32), DYN_DEST, DYN_32bit);
    } else {
        movToRegFromCpu(DYN_SRC, offsetof(CPU, reg[4].u16), DYN_16bit);
        instRegImm('+', DYN_SRC, DYN_16bit, 2);
        movToCpuFromReg(offsetof(CPU, reg[4].u16), DYN_DEST, DYN_16bit);
    }
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushSeg32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_push32, false, false, false, 2, 0, DYN_PARAM_CPU, offsetof(CPU, seg[op->reg].value), DYN_PARAM_CPU_ADDRESS_32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popSeg32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_peek32, true, false, false, 2, 0, DYN_PARAM_CPU, 0, DYN_PARAM_CONST_32);
    callHostFunction(common_setSegment, true, false, true, 3, 0, DYN_PARAM_CPU, op->reg, DYN_PARAM_CONST_32, DYN_CALL_RESULT, DYN_PARAM_REG_32);
    if (cpu->stackMask==0xFFFFFFFF) {
        movToRegFromCpu(DYN_SRC, offsetof(CPU, reg[4].u32), DYN_32bit);
        instRegImm('+', DYN_SRC, DYN_32bit, 4);
        movToCpuFromReg(offsetof(CPU, reg[4].u32), DYN_DEST, DYN_32bit);
    } else {
        movToRegFromCpu(DYN_SRC, offsetof(CPU, reg[4].u16), DYN_16bit);
        instRegImm('+', DYN_SRC, DYN_16bit, 4);
        movToCpuFromReg(offsetof(CPU, reg[4].u16), DYN_DEST, DYN_16bit);
    }
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushA16(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_pushA16, false, false, false, 1, 0, DYN_PARAM_CPU);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushA32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_pushA32, false, false, false, 1, 0, DYN_PARAM_CPU);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popA16(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_popA16, false, false, false, 1, 0, DYN_PARAM_CPU);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popA32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_popA32, false, false, false, 1, 0, DYN_PARAM_CPU);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_push16imm(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_push16, false, false, false, 2, 0, DYN_PARAM_CPU, op->imm, DYN_PARAM_CONST_16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_push32imm(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_push32, false, false, false, 2, 0, DYN_PARAM_CPU, op->imm, DYN_PARAM_CONST_32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popf16(CPU* cpu, DecodedOp* op) {
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NONE);
    callHostFunction(common_pop16, true, false, false, 1, 0, DYN_PARAM_CPU);
    callHostFunction(common_setFlags, false, false, false, 3, 0, DYN_PARAM_CPU, DYN_CALL_RESULT, DYN_PARAM_REG_16, FMASK_ALL & 0xFFFF, DYN_PARAM_CONST_16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_popf32(CPU* cpu, DecodedOp* op) {
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NONE);
    callHostFunction(common_pop32, true, false, false, 1, 0, DYN_PARAM_CPU);
    callHostFunction(common_setFlags, false, false, false, 3, 0, DYN_PARAM_CPU, DYN_CALL_RESULT, DYN_PARAM_REG_32, FMASK_ALL, DYN_PARAM_CONST_32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushf16(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_fillFlags, false, false, false, 1, 0, DYN_PARAM_CPU);
    movToRegFromCpu(DYN_SRC, offsetof(CPU, flags), DYN_32bit);
    instRegImm('|', DYN_SRC, DYN_32bit, 2);
    callHostFunction(common_push16, false, false, false, 3, 0, DYN_PARAM_CPU, DYN_SRC, DYN_PARAM_REG_32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_pushf32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_fillFlags, false, false, false, 1, 0, DYN_PARAM_CPU);
    movToRegFromCpu(DYN_SRC, offsetof(CPU, flags), DYN_32bit);
    instRegImm('|', DYN_SRC, DYN_32bit, 2);
    instRegImm('&', DYN_SRC, DYN_32bit, 0xFCFFFF);
    callHostFunction(common_push32, false, false, false, 3, 0, DYN_PARAM_CPU, DYN_SRC, DYN_PARAM_REG_32);
    INCREMENT_EIP(op->len);
}
