void * __cdecl class_vbase_map_decorated_name(c1_symbol *sym,c1_vbase_map_key *key)

{
  c1_type *pcVar1;
  char *s;
  void *pvVar2;
  
  pcVar1 = sym->type;
  sym->type = g_type_const_int;
  sym->flags1 = sym->flags1 & 0xfc;
  sym->storage = sym->storage & 0xf8 ^ 2;
  (sym->tail).data.value_lo = (c1_u32)key->cls_b;
  s = decorate_name(sym,key->cls_a);
  pvVar2 = name_intern(s);
  sym->type = pcVar1;
  return pvVar2;
}

