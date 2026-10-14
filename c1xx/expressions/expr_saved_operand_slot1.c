int __fastcall expr_saved_operand_slot1(int *rec)

{
  if (rec[1] == 0) {
    rec[1] = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*rec + 0x14) + 0x14) + 0x10) + 0x14) +
                     0x10);
  }
  return rec[1];
}

