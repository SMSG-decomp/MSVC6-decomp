void __fastcall decl_check_declarator_void_fragment(int *rec)

{
  diag_error(0xb6,rec[0xd]);
  *(byte *)(rec + 0xf) = *(byte *)(rec + 0xf) | 1;
  *rec = (int)g_type_int;
  if ((((*(byte *)rec[2] & 0x8f) == 0x83) && ((*(ushort *)*rec & 0x200) != 0)) &&
     ((*(byte *)(*(int *)((ushort *)*rec + 4) + 5) & 1) != 0)) {
    diag_error(0xe9,rec[0xd]);
    *(byte *)(rec + 0xf) = *(byte *)(rec + 0xf) | 1;
  }
  *(int *)(rec[2] + 4) = *rec;
  return;
}

