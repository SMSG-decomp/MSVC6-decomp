void __cdecl format_storage_class_to_file(uint spec0,uint spec1,uint spec2,FILE *out)

{
  char cVar1;
  int iVar2;
  char *_Str;
  uint uVar3;
  char *pcVar4;
  
  iVar2 = format_buffer_acquire();
  format_buffer_free(iVar2);
  iVar2 = format_storage_class(0,spec0,spec1,spec2);
  _Str = format_buffer_text(iVar2);
  uVar3 = 0xffffffff;
  pcVar4 = _Str;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  fwrite(_Str,~uVar3 - 1,1,out);
  format_buffer_free(iVar2);
  format_buffer_leave();
  return;
}

