uint __fastcall il_symbol_key_2(fe_file_record *file)

{
  uint uVar1;
  
  if (g_c9il_mode != '\0') {
    return file->entity & 0xffffff;
  }
  if ((file->key_ref & 0xfffffff8) != 0) {
    return file->key_ref >> 3;
  }
  uVar1 = sym_assign_namemap_key((int *)file);
  return uVar1;
}

