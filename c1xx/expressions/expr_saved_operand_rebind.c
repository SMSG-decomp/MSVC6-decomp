int __fastcall expr_saved_operand_rebind(int *rec)

{
  int iVar1;
  c1_node *pcVar2;
  
  if (rec[3] != 0) {
    expr_saved_operand_slot1(rec);
    iVar1 = *(int *)(*(int *)(rec[1] + 8) + 0x14);
    pcVar2 = tree_new_sized_int_constant(*(uint *)(rec[3] + 0x10),*(int *)(rec[3] + 0x14),4);
    *(c1_node **)(iVar1 + 0x10) = pcVar2;
    return *rec;
  }
  return *rec;
}

