int __fastcall expr_saved_operand_slot2(int *rec)

{
  if (rec[2] == 0) {
    rec[2] = *(int *)(*(int *)(*(int *)(*(int *)(*rec + 0x14) + 0x14) + 0x14) + 0x10);
  }
  return rec[2];
}

