c1_node * __cdecl
expr_build_new_or_placeholder(char kind,int placement,c1_symbol *type_sym,int init,int bound)

{
  c1_node *pcVar1;
  
  if (((byte)g_compile_flags_cc & 0x20) == 0) {
    pcVar1 = expr_build_new(kind,placement,type_sym,init,(c1_node *)0x0,bound);
    return pcVar1;
  }
  pcVar1 = tree_new_int_constant(0);
  return pcVar1;
}

