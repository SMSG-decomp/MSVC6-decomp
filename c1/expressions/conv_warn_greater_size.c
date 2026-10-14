c1_node * __cdecl conv_warn_greater_size(c1_node *node,c1_type *type,c1_u8 op)

{
  c1_node *pcVar1;
  
  diag_warning(4,0x132,op);
  pcVar1 = conv_convert_basic(op,type,node);
  return pcVar1;
}

