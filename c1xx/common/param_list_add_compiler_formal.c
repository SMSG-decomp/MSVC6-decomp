void __thiscall param_list_add_compiler_formal(void *list,void *name,c1_type *type)

{
  c1_symbol *sym;
  
  sym = decl_new_compiler_formal(name,type);
  sym_list_append(list,sym);
  return;
}

