int __cdecl format_pointer_layer_text(int buf,c1_type *layer)

{
  c1_u16 quals;
  int iVar1;
  
  quals = layer->flags;
  iVar1 = decorate_cv_text(buf,quals);
  format_buffer_prepend_char(iVar1,'*');
  if (g_ms_extensions != '\0') {
    iVar1 = format_calling_convention_text
                      (iVar1,format_buffer_prepend_string,quals,(layer->extra).count,layer);
    return iVar1;
  }
  return iVar1;
}

