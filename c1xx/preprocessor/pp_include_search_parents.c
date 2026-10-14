int __cdecl pp_include_search_parents(byte *file,char quoted,byte *file2)

{
  int iVar1;
  fe_input_file *pfVar2;
  
  pfVar2 = g_input_file;
  iVar1 = pp_include_search_path(file,(byte *)g_input_file->file->name->text,'\x01',quoted,file2);
  if (iVar1 == -1) {
    while (pfVar2 = pfVar2->next, pfVar2 != (fe_input_file *)0x0) {
      iVar1 = pp_include_search_path(file,(byte *)pfVar2->file->name->text,'\x01',quoted,file2);
      if (iVar1 != -1) {
        return iVar1;
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}

