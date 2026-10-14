int __cdecl format_symbol_name_and_declarator(c1_symbol *sym,c1_type *type)

{
  c1_type *pcVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  int handle;
  ushort modifier;
  
  iVar3 = format_buffer_alloc();
  if ((sym != (c1_symbol *)0x0) && (sym->name != g_name_formal)) {
    pcVar1 = sym->type;
    if (((char)pcVar1->code < '\0') && (pcVar1 != (c1_type *)0x0)) {
      modifier = *(ushort *)((-(uint)((pcVar1->code & 0x80) != 0) & (uint)pcVar1) + 2);
    }
    else {
      modifier = 0;
    }
    iVar3 = format_calling_convention_text
                      (iVar3,format_buffer_append_string,modifier,(pcVar1->extra).count,pcVar1);
    pcVar4 = sym->name->text;
    if (*pcVar4 == '?') {
      if (g_undecorate_hook == (code *)0x0) {
        pcVar4 = (char *)__unDName(0,sym->name->text,0,format_undname_alloc,0,0x1800);
        format_buffer_append_string(iVar3,pcVar4);
      }
      else {
        pcVar4 = (char *)(*g_undecorate_hook)(0,pcVar4,0,format_undname_alloc,0);
        format_buffer_append_string(iVar3,pcVar4);
      }
    }
    else {
      if (sym->scope_index != 0) {
        format_qualified_name(iVar3,&g_scope_vector->entries[(short)sym->scope_index]->kind);
        format_buffer_append_string(iVar3,"::");
      }
      bVar2 = sym->kind & 0x1f;
      if (((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) {
        if ((sym->flags1 & 0x20) == 0x20) {
          format_buffer_append_char(iVar3,'~');
        }
        bVar2 = sym->flags1;
        if (((bVar2 & 0x10) == 0x10) || ((bVar2 & 0x20) == 0x20)) {
          format_qualified_name(iVar3,&g_scope_vector->entries[(short)sym->scope_index]->kind);
          goto LAB_10452a7a;
        }
        if ((sym->tail).fn.op_token != '\x01') {
          if ((bVar2 & 0x40) != 0) {
            pcVar1 = sym->type;
            if (g_format_conversion_by_name == 0) {
              format_buffer_append_string(iVar3,"operator`");
              handle = format_symbol_declaration_text((c1_symbol *)0x0,pcVar1->base);
              pcVar4 = format_buffer_text(handle);
              format_buffer_append_string(iVar3,pcVar4);
              format_buffer_free(handle);
              format_buffer_append_string(iVar3,"\'(void)");
            }
            else {
              format_buffer_append_string(iVar3,"operator\"");
              format_buffer_append_string(iVar3,sym->name->text);
              format_buffer_append_string(iVar3,"\"(void)");
            }
            format_cv_suffix(iVar3,(c1_type *)
                                   **(undefined4 **)
                                     ((-(uint)((sym->type->code & 0x80) != 0) & (uint)sym->type) + 8
                                     ));
            return iVar3;
          }
          format_buffer_append_string(iVar3,"operator ");
          format_buffer_append_string(iVar3,sym->name->text);
          goto LAB_10452a7a;
        }
      }
      format_buffer_append_string(iVar3,sym->name->text);
    }
  }
LAB_10452a7a:
  if (type == (c1_type *)0x0) {
    return iVar3;
  }
  iVar3 = format_declarator_suffix_text
                    (iVar3,(ushort *)((uint)type & -(uint)((type->code & 0x80) != 0)));
  return iVar3;
}

