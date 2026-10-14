c1_node * __cdecl conv_warn_function_to_data_pointer(uint code,c1_node *node,c1_type *type,c1_u8 op)

{
  c1_node *pcVar1;
  
  if (((short)code != 0x82) && ((short)code != 0x83)) {
    pcVar1 = conv_convert_basic(op,type,node);
    return pcVar1;
  }
  if (g_ms_extensions != '\0') {
    diag_warning(4,0x36,op);
    pcVar1 = conv_convert_basic(op,type,node);
    return pcVar1;
  }
  diag_warning(1,0x36,op);
  pcVar1 = conv_convert_basic(op,type,node);
  return pcVar1;
}

