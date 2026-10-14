void __cdecl decl_report_bad_specifier(short n,byte *spec)

{
  int iVar1;
  char *pcVar2;
  
  if ((*spec & 0x10) == 0) {
    diag_error(n,0x54,*(undefined4 *)(spec + 0xc));
    return;
  }
  iVar1 = format_buffer_acquire();
  format_buffer_free(iVar1);
  iVar1 = format_storage_class(0,*(uint *)spec,*(uint *)(spec + 4),*(uint *)(spec + 8));
  pcVar2 = format_buffer_text(iVar1);
  diag_error(n,0x73,pcVar2);
  format_buffer_leave();
  return;
}

