void __fastcall decl_specifiers_add_storage_class(int *spec_rec,int value)

{
  if (((byte)g_compile_flags_c8 & 8) == 0) {
    decl_specifiers_merge
              ((byte *)(spec_rec + 5),(byte)g_tree_op_to_il_op[*(byte *)*spec_rec],'\x01',value);
    *(undefined1 *)(spec_rec + 0xb) = 1;
    return;
  }
  diag_error(0x2d1,(uint)*(byte *)*spec_rec);
  *(byte *)(spec_rec + 5) = *(byte *)(spec_rec + 5) | 8;
  return;
}

