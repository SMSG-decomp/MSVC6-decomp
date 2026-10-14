void __fastcall expr_saved_operand_split_pair(int *rec)

{
  int iVar1;
  
  iVar1 = *(int *)(*rec + 0x14);
  rec[1] = *(int *)(iVar1 + 0x10);
  rec[2] = *(int *)(iVar1 + 0x14);
  return;
}

