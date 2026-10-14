c1_node * __thiscall
conv_new_temporary_variable_address(c1_conversion *conv,c1_type *type,c1_symbol **out)

{
  byte storage;
  c1_symbol *sym;
  c1_node *pcVar1;
  
  if (conv->target_kind == 3) {
    storage = conv->target_symbol->storage & 7;
  }
  else {
    storage = 4;
  }
  sym = decl_new_compiler_variable_hoisted(storage,type);
  *out = sym;
  pcVar1 = expr_reference_named_entity(sym,0);
  pcVar1 = expr_build_address_of(pcVar1,4);
  return pcVar1;
}

