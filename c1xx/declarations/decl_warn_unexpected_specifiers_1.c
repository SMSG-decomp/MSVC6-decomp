c1_u8 __cdecl decl_warn_unexpected_specifiers_1(c1xx_decl_specifiers *spec)

{
  c1_u8 cVar1;
  ushort quals;
  int iVar2;
  c1_type *pcVar3;
  int iVar4;
  c1xx_decl_specifiers *pcVar5;
  c1_u32 *arg_word;
  uint in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  uint in_stack_ffffffdc;
  uint in_stack_ffffffe0;
  c1xx_decl_specifiers *spec_10;
  uint class_flags;
  c1_u8 local_1;
  
  local_1 = '\0';
  iVar2 = format_buffer_acquire();
  spec_10 = (c1xx_decl_specifiers *)0x1044d787;
  format_buffer_free(iVar2);
  class_flags = 0x1044d78f;
  iVar2 = format_buffer_alloc();
  if ((spec->spec[0] & 0x20) == 0) {
LAB_1047bca2:
    pcVar5 = spec;
    arg_word = (c1_u32 *)&stack0xffffffd4;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *arg_word = *(c1_u32 *)pcVar5->spec;
      pcVar5 = (c1xx_decl_specifiers *)(pcVar5->spec + 4);
      arg_word = arg_word + 1;
    }
    iVar2 = format_decl_specifiers_text
                      (iVar2,in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0
                       ,(uint)spec_10,class_flags);
    local_1 = '\x01';
  }
  else {
    class_flags = 0;
    in_stack_ffffffe0 = 0x1044d7a7;
    spec_10 = spec;
    cVar1 = decl_warn_unexpected_specifiers_2(spec,'\0');
    if (cVar1 != '\0') goto LAB_1047bca2;
  }
  if ((spec->spec[0] & 0x10) == 0) {
    if (spec->type_sym == (c1_symbol *)0x0) {
      if ((spec->type == g_type_int) && ((spec->spec[0x14] & 4) == 0)) goto LAB_1044d7dd;
      iVar2 = format_type_name_text(iVar2,spec->type,'\x01');
      local_1 = '\x01';
    }
    else {
      quals = ~spec->type_sym->type->flags & spec->type->flags;
      if (quals != 0) {
        iVar2 = decorate_cv_text(iVar2,quals);
      }
      iVar2 = format_symbol_name_text(iVar2,spec->type_sym);
      local_1 = '\x01';
    }
  }
  else {
    pcVar3 = spec->type;
    if (pcVar3 != (c1_type *)0x0) {
      if ((pcVar3->code & 0x8f) == 0x83) {
        pcVar3 = type_skip_arrays(pcVar3->base);
      }
      if ((pcVar3->flags & 0x3e0) != 0) {
        pcVar3 = spec->type;
        if ((pcVar3->code & 0x8f) == 0x83) {
          pcVar3 = type_skip_arrays(pcVar3->base);
        }
        iVar2 = decorate_cv_text(iVar2,pcVar3->flags & 0x3e0);
        local_1 = '\x01';
        goto LAB_1047bd02;
      }
    }
LAB_1044d7dd:
    if (local_1 == '\0') goto LAB_1044d7e9;
  }
LAB_1047bd02:
  format_buffer_text(iVar2);
  diag_warning(1,0x206);
LAB_1044d7e9:
  format_buffer_leave();
  return local_1;
}

