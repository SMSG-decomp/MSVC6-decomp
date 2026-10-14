c1_u8 __cdecl decl_warn_unexpected_specifiers_2(c1xx_decl_specifiers *spec,c1_u8 report)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  c1_u8 cVar4;
  uint class_flags;
  char *pcVar5;
  int iVar6;
  int iVar7;
  c1xx_decl_specifiers *pcVar8;
  c1_u32 *pcVar9;
  c1_u32 *arg_word_2;
  c1_u32 *arg_word;
  uint in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  uint in_stack_ffffffc4;
  uint in_stack_ffffffc8;
  uint spec_10;
  c1_u32 local_18 [6];
  
  pcVar9 = local_18;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pcVar9 = 0;
    pcVar9 = pcVar9 + 1;
  }
  bVar1 = spec->spec[0];
  bVar2 = spec->spec[0];
  bVar3 = spec->spec[0];
  spec->spec[0] = bVar3 & 0x4f;
  pcVar8 = spec;
  arg_word_2 = (c1_u32 *)&stack0xffffffbc;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *arg_word_2 = *(c1_u32 *)pcVar8->spec;
    pcVar8 = (c1xx_decl_specifiers *)(pcVar8->spec + 4);
    arg_word_2 = arg_word_2 + 1;
  }
  cVar4 = decl_specifiers_merge_modifiers((byte *)local_18,in_stack_ffffffbc);
  spec->spec[0] =
       (((bVar3 >> 7) << 2 | bVar1 >> 5 & 1) << 1 | bVar2 >> 4 & 1) << 4 | spec->spec[0] & 0x4f;
  if ((cVar4 != '\0') && (report != '\0')) {
    class_flags = format_buffer_acquire();
    format_buffer_free(class_flags);
    spec_10 = 0x1047bc68;
    iVar6 = format_buffer_alloc();
    pcVar9 = local_18;
    arg_word = (c1_u32 *)&stack0xffffffbc;
    for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
      *arg_word = *pcVar9;
      pcVar9 = pcVar9 + 1;
      arg_word = arg_word + 1;
    }
    iVar6 = format_decl_specifiers_text
                      (iVar6,in_stack_ffffffbc,in_stack_ffffffc0,in_stack_ffffffc4,in_stack_ffffffc8
                       ,spec_10,class_flags);
    pcVar5 = format_buffer_text(iVar6);
    diag_warning(1,0x206,pcVar5);
    format_buffer_leave();
  }
  return cVar4;
}

