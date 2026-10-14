int __cdecl format_pointer_declarator_text(int buf,c1_type *type)

{
  ushort quals;
  ushort uVar1;
  int iVar2;
  int iVar3;
  char *s;
  
  quals = type->flags;
  iVar2 = decorate_cv_text(buf,quals);
  format_buffer_prepend_char(iVar2,(-((type->code & 0x8f) != 0x80) & 4U) + 0x26);
  uVar1 = type->code & 0x8f;
  if ((uVar1 == 0x8a) || (uVar1 == 0x8e)) {
    format_buffer_prepend_string(iVar2,"::");
    iVar3 = format_buffer_acquire();
    format_buffer_free(iVar3);
    iVar3 = format_buffer_alloc();
    format_qualified_name(iVar3,&((type->extra).cls)->kind);
    s = format_buffer_text(iVar3);
    format_buffer_prepend_string(iVar2,s);
    format_buffer_free(iVar3);
    format_buffer_leave();
  }
  if (g_ms_extensions != '\0') {
    iVar2 = format_calling_convention_text
                      (iVar2,format_buffer_prepend_string,quals,(type->extra).count,type);
    return iVar2;
  }
  return iVar2;
}

