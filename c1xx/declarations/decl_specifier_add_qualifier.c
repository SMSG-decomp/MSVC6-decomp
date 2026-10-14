undefined4 __fastcall decl_specifier_add_qualifier(undefined4 *state,undefined4 eax)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = CONCAT31((int3)((uint)eax >> 8),(byte)g_compile_flags_c8);
  if ((((byte)g_compile_flags_c8 & 8) != 0) ||
     (((uVar1 = 2, (g_paren_level_flags[g_paren_depth] & 2) == 0 &&
       (((byte)g_compile_flags_c4 & 4) == 0)) || (state[2] != 0)))) {
    uVar2 = type_merge_qualifiers
                      (CONCAT22((short)((uint)uVar1 >> 0x10),*(undefined2 *)((int)state + 0x42)),
                       CONCAT22((short)((uint)*state >> 0x10),
                                (short)g_tree_op_to_il_op[*(byte *)*state]));
    *(short *)((int)state + 0x42) = (short)uVar2;
    uVar1 = 0;
  }
  return uVar1;
}

