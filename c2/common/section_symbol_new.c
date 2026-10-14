c2_fe_symbol * __fastcall section_symbol_new(uint32_t name,uint32_t class_name,uint32_t number)

{
  c2_fe_symbol *fsym;
  
  fsym = fe_symbol_alloc('\t',0);
  fsym->id = number;
  fsym->name = (char *)name;
  fsym->storage = class_name;
  fe_symbol_hash_insert(fsym,0);
  section_list_append(fsym);
  return fsym;
}

