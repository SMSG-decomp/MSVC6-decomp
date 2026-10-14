void __fastcall format_local_label_name(int n,char *out)

{
  int iVar1;
  
  iVar1 = format_integer(g_cur_func_sym->id,out,10);
  out[iVar1] = '$';
  format_integer(0x3fffff - n,out + iVar1 + 1,10);
  return;
}

