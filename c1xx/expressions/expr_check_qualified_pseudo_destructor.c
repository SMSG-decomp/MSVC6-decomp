c1_node * __cdecl
expr_check_qualified_pseudo_destructor
          (c1_u8 op,c1_node *object,c1xx_decl_specifiers *scope_type,c1xx_decl_specifiers *dtor_type
          )

{
  c1_scope_stack *pcVar1;
  
  if (scope_type->type != dtor_type->type) {
    diag_error(0x3e,dtor_type->type);
  }
  pcVar1 = g_current_scope;
  g_current_scope->reported = '\0';
  pcVar1->qual_class = (c1_symbol *)0x0;
  pcVar1->access_op = '\x01';
  pcVar1->qualified = '\0';
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffffffbf;
  return object;
}

