c1_symbol * __cdecl func_new_dynamic_initializer(void)

{
  void *name;
  c1_symbol *sym;
  c1_type *pcVar1;
  byte bVar2;
  char local;
  
  local = '\0';
  name = name_new_E();
  sym = sym_new_object(name,local);
  *(byte *)((int)&sym->tail + 0xb) = *(byte *)((int)&sym->tail + 0xb) | 2;
  if (g_class_depth < 0) {
    sym->kind = sym->kind & 0xe7 | 7;
  }
  else {
    sym->kind = sym->kind & 0xe8 | 8;
  }
  bVar2 = sym->storage & 0xf8 ^ 3;
  sym->storage = bVar2;
  sym->storage = '\0';
  sym->flags21 = '\0';
  sym->flags22 = '\0';
  sym->flags23 = '\0';
  sym->storage = (sym->storage ^ bVar2 & 7) & 7 ^ sym->storage;
  pcVar1 = sym_new_builtin_helper(1,g_type_void);
  sym->type = pcVar1;
  sym->flags5 = sym->flags5 | 0x80;
  if (g_code_seg_name != (void *)0x0) {
    sym_set_segment_checked(sym,g_code_seg_name);
  }
  bVar2 = sym->flags1;
  (sym->tail).fn.op_token = '\x01';
  sym->flags1 = bVar2 & 0xfe | 2;
  return sym;
}

