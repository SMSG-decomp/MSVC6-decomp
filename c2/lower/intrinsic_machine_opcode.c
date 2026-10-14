int __fastcall intrinsic_machine_opcode(int intrinsic_id)

{
  int iVar1;
  
  iVar1 = lookup_opcode_pair_table(g_intrinsic_opcode_table,intrinsic_id);
  return iVar1;
}

