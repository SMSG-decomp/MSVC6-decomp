int __fastcall x87_arith_op_index(uint32_t op)

{
  if ((0x44 < (int)op) && ((int)op < 0x4b)) {
    return op - 0x45;
  }
  return -1;
}

