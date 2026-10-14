void __cdecl decl_check_empty_declaration(byte *spec)

{
  byte bVar1;
  ushort tag_code;
  c1_symbol *pcVar2;
  c1_symbol *pcVar3;
  int iVar4;
  c1_u32 *pcVar5;
  c1_u32 *spec_arg_2;
  c1_u32 *spec_arg;
  uint in_stack_ffffffd8;
  void *in_stack_ffffffdc;
  uint in_stack_ffffffe0;
  uint in_stack_ffffffe4;
  uint in_stack_ffffffe8;
  uint uVar6;
  
  pcVar5 = (c1_u32 *)spec;
  tag_code = **(ushort **)(spec + 0x18);
  if ((tag_code & 0x4f0) != 0) {
    if (g_ms_extensions != '\0') {
      iVar4 = format_buffer_acquire();
      uVar6 = 0x104728ca;
      format_buffer_free(iVar4);
      spec_arg_2 = (c1_u32 *)&stack0xffffffd8;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *spec_arg_2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        spec_arg_2 = spec_arg_2 + 1;
      }
      iVar4 = format_decl_specifiers_text
                        (0,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4,
                         in_stack_ffffffe8,uVar6);
      format_buffer_text(iVar4);
      diag_warning(2,0x5b);
      format_buffer_leave();
      return;
    }
LAB_10472935:
    diag_error(0x3b);
    return;
  }
  if ((((tag_code & 0x200) != 0) && (bVar1 = spec[1], (bVar1 & 4) == 0)) &&
     ((g_compile_flags_c4 & 0x200) == 0)) {
    iVar4 = *(int *)(*(ushort **)(spec + 0x18) + 4);
    if ((*(byte *)(iVar4 + 3) & 1) != 0) {
      if ((tag_code & 0x20f) == 0x203) {
        decl_declare_anonymous_union((c1xx_decl_specifiers *)spec);
        return;
      }
      if (g_ms_extensions != '\0') {
        diag_warning(2,0x5e);
        return;
      }
      goto LAB_10472935;
    }
    if ((((((*spec & 0x20) == 0) || ((bVar1 & 3) != 0)) ||
         (((spec[2] & 0xf) != 0 || (((spec[3] & 0x9d) != 0 || ((spec[2] & 0x40) != 0)))))) ||
        ((spec[0x14] & 3) != 0)) || ((bVar1 & 0x40) != 0)) {
      iVar4 = format_buffer_acquire();
      uVar6 = 0x104729f8;
      format_buffer_free(iVar4);
      spec_arg = (c1_u32 *)&stack0xffffffd8;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *spec_arg = *pcVar5;
        pcVar5 = pcVar5 + 1;
        spec_arg = spec_arg + 1;
      }
      iVar4 = format_decl_specifiers_text
                        (0,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4,
                         in_stack_ffffffe8,uVar6);
      format_buffer_text(iVar4);
      diag_warning(1,0x5b);
      format_buffer_leave();
    }
    else if (g_qualified_lookup_found_overloads == 0) {
      spec = (byte *)scope_insert_through_object;
      pcVar2 = decl_tag_declare(*(fe_name **)(iVar4 + 8),tag_code,&spec,'\0');
      if (spec != (byte *)0x0) {
        (*(code *)spec)();
      }
      if (pcVar2 != (c1_symbol *)0x0) {
        if (-1 < g_class_depth) {
          pcVar2->flags2 =
               (g_class_def_stack[g_class_depth].flags ^ pcVar2->flags2) & 3 ^ pcVar2->flags2;
          pcVar2->scope_index = (((g_class_def_stack[g_class_depth].cls)->detail).cls)->scope_index;
          return;
        }
        if ((g_current_scope->current->kind == '\0') &&
           (g_current_scope->current != g_current_scope->global_scope)) {
          pcVar3 = scope_current_namespace(g_current_scope);
          pcVar2->scope_index = *(c1_u16 *)&pcVar3->type->base;
          return;
        }
      }
    }
  }
  return;
}

