void __cdecl decl_emit_prototype_specifiers(c1_symbol_attrs attrs,FILE *out)

{
  char cVar1;
  uint uVar2;
  char *_Str;
  int iVar3;
  c1_u32 *arg_word;
  char *pcVar4;
  uint in_stack_ffffffe0;
  void *in_stack_ffffffe4;
  uint in_stack_ffffffe8;
  uint in_stack_ffffffec;
  uint spec_10;
  
  uVar2 = format_buffer_acquire();
  spec_10 = 0x104849ef;
  format_buffer_free(uVar2);
  arg_word = (c1_u32 *)&stack0xffffffe0;
  for (iVar3 = 6; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar3 != 0;
      iVar3 = iVar3 + -1) {
    *arg_word = *(c1_u32 *)register0x00000010;
    arg_word = arg_word + 1;
  }
  iVar3 = format_decl_specifiers_text
                    (0,in_stack_ffffffe0,in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,
                     spec_10,uVar2);
  _Str = format_buffer_text(iVar3);
  uVar2 = 0xffffffff;
  pcVar4 = _Str;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  fwrite(_Str,~uVar2 - 1,1,(FILE *)out);
  format_buffer_free(iVar3);
  format_buffer_leave();
  return;
}

