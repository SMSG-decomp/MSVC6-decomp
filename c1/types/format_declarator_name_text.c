int __cdecl format_declarator_name_text(c1_symbol *sym,c1_type *type)

{
  c1_type *type_00;
  int iVar1;
  c1_u16 modifier;
  
  iVar1 = format_buffer_alloc();
  if ((sym != (c1_symbol *)0x0) && (sym->name != g_name_formal)) {
    type_00 = sym->type;
    if (((char)type_00->code < '\0') && (type_00 != (c1_type *)0x0)) {
      modifier = *(c1_u16 *)((-(uint)((type_00->code & 0x80) != 0) & (uint)type_00) + 2);
    }
    else {
      modifier = 0;
    }
    iVar1 = format_calling_convention_text
                      (iVar1,format_buffer_append_string,modifier,(type_00->extra).count,type_00);
    format_buffer_append_string(iVar1,sym->name->text);
  }
  if (type == (c1_type *)0x0) {
    return iVar1;
  }
  iVar1 = format_type_declarator_text
                    (iVar1,(c1_type *)((uint)type & -(uint)((type->code & 0x80) != 0)));
  return iVar1;
}

