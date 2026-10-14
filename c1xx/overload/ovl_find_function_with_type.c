int __cdecl
ovl_find_function_with_type
          (c1_symbol *sym,c1_type *type,int complain,int skip_templates,c1_symbol *probe,
          c1_declarator *d,int mode)

{
  c1_symbol *pcVar1;
  void **ppvVar2;
  c1_symbol *pcVar3;
  uint *link;
  
  if ((sym->kind & 0x1f) != 0x1b) {
    ppvVar2 = ovl_chain_find_function_with_type
                        (sym,type,(char)complain,(char)skip_templates,probe,d,mode);
    return (int)ppvVar2;
  }
  link = *(uint **)sym->type;
  sym = (c1_symbol *)0x0;
  while (((pcVar3 = (c1_symbol *)
                    ovl_chain_find_function_with_type
                              ((c1_symbol *)*link,type,(char)complain,(char)skip_templates,probe,d,
                               mode), pcVar1 = sym, pcVar3 == (c1_symbol *)0x0 ||
          (pcVar1 = pcVar3, sym == (c1_symbol *)0x0)) || (pcVar1 = sym, sym == pcVar3))) {
    sym = pcVar1;
    link = (uint *)link[2];
    if (link == (uint *)0x0) {
      return (int)sym;
    }
  }
  return 0;
}

