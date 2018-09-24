void OPCALL dynamic_inc8_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    movToCpuFromCpu(offsetof(CPU, dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST);
    instRegImm('+', DYN_DEST, DYN_8bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u8), DYN_DEST, DYN_8bit);
    movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_INC8);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_inc8_mem32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(offsetof(CPU, dst.u8), DYN_8bit, DYN_ADDRESS);
    instRegImm('+', DYN_READ_RESULT, DYN_8bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u8), DYN_READ_RESULT, DYN_8bit);
    movToMemFromReg(DYN_ADDRESS, DYN_READ_RESULT, DYN_8bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_INC8);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_inc16_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    movToCpuFromCpu(offsetof(CPU, dst.u16), offsetof(CPU, reg[op->reg].u16), DYN_16bit, DYN_DEST);
    instRegImm('+', DYN_DEST, DYN_16bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u16), DYN_DEST, DYN_16bit);
    movToCpuFromReg(offsetof(CPU, reg[op->reg].u16), DYN_DEST, DYN_16bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_INC16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_inc16_mem32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(offsetof(CPU, dst.u16), DYN_16bit, DYN_ADDRESS);
    instRegImm('+', DYN_READ_RESULT, DYN_16bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u16), DYN_READ_RESULT, DYN_16bit);
    movToMemFromReg(DYN_ADDRESS, DYN_READ_RESULT, DYN_16bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_INC16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_inc32_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    movToCpuFromCpu(offsetof(CPU, dst.u32), offsetof(CPU, reg[op->reg].u32), DYN_32bit, DYN_DEST);
    instRegImm('+', DYN_DEST, DYN_32bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u32), DYN_DEST, DYN_32bit);
    movToCpuFromReg(offsetof(CPU, reg[op->reg].u32), DYN_DEST, DYN_32bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_INC32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_inc32_mem32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(offsetof(CPU, dst.u32), DYN_32bit, DYN_ADDRESS);
    instRegImm('+', DYN_READ_RESULT, DYN_32bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u32), DYN_READ_RESULT, DYN_32bit);
    movToMemFromReg(DYN_ADDRESS, DYN_READ_RESULT, DYN_32bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_INC32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_dec8_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    movToCpuFromCpu(offsetof(CPU, dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST);
    instRegImm('-', DYN_DEST, DYN_8bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u8), DYN_DEST, DYN_8bit);
    movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_DEC8);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_dec8_mem32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(offsetof(CPU, dst.u8), DYN_8bit, DYN_ADDRESS);
    instRegImm('-', DYN_READ_RESULT, DYN_8bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u8), DYN_READ_RESULT, DYN_8bit);
    movToMemFromReg(DYN_ADDRESS, DYN_READ_RESULT, DYN_8bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_DEC8);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_dec16_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    movToCpuFromCpu(offsetof(CPU, dst.u16), offsetof(CPU, reg[op->reg].u16), DYN_16bit, DYN_DEST);
    instRegImm('-', DYN_DEST, DYN_16bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u16), DYN_DEST, DYN_16bit);
    movToCpuFromReg(offsetof(CPU, reg[op->reg].u16), DYN_DEST, DYN_16bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_DEC16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_dec16_mem32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(offsetof(CPU, dst.u16), DYN_16bit, DYN_ADDRESS);
    instRegImm('-', DYN_READ_RESULT, DYN_16bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u16), DYN_READ_RESULT, DYN_16bit);
    movToMemFromReg(DYN_ADDRESS, DYN_READ_RESULT, DYN_16bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_DEC16);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_dec32_reg(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    movToCpuFromCpu(offsetof(CPU, dst.u32), offsetof(CPU, reg[op->reg].u32), DYN_32bit, DYN_DEST);
    instRegImm('-', DYN_DEST, DYN_32bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u32), DYN_DEST, DYN_32bit);
    movToCpuFromReg(offsetof(CPU, reg[op->reg].u32), DYN_DEST, DYN_32bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_DEC32);
    INCREMENT_EIP(op->len);
}
void OPCALL dynamic_dec32_mem32(CPU* cpu, DecodedOp* op) {
    callHostFunction(common_getCF, true, false, false, 1, 0, DYN_PARAM_CPU);
    movToCpuFromReg(offsetof(CPU, oldCF), DYN_CALL_RESULT, DYN_32bit);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(offsetof(CPU, dst.u32), DYN_32bit, DYN_ADDRESS);
    instRegImm('-', DYN_READ_RESULT, DYN_32bit, 1);
    movToCpuFromReg(offsetof(CPU, result.u32), DYN_READ_RESULT, DYN_32bit);
    movToMemFromReg(DYN_ADDRESS, DYN_READ_RESULT, DYN_32bit);
    movToCpu(offsetof(CPU, lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_DEC32);
    INCREMENT_EIP(op->len);
}
