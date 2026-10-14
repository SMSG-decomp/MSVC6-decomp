void __thiscall hash_scope_lookup_anonymous_member(c1_scope_object *hash_scope,void *name,int *out)

{
  void *pvVar1;
  c1_symbol *pcVar2;
  int iVar3;
  uint bucket;
  
  bucket = 0;
  if (hash_scope->mask != 0xffffffff) {
    do {
      for (pvVar1 = (hash_scope->entries).buckets[bucket]; pvVar1 != (void *)0x0;
          pvVar1 = *(void **)((int)pvVar1 + 4)) {
        if (((((*(byte *)((int)pvVar1 + -8) & 0x1f) == 4) &&
             ((**(ushort **)((int)pvVar1 + 0xc) & 0x200) != 0)) &&
            (*(int *)((int)pvVar1 + 0x2c) != 0)) &&
           (pcVar2 = sym_chain_find_name((c1_symbol *)
                                         (*(int *)(*(int *)((int)pvVar1 + 0x2c) + 4) + -8),name),
           pcVar2 != (c1_symbol *)0x0)) {
          if ((pcVar2 != (c1_symbol *)*out) && ((c1_symbol *)*out != (c1_symbol *)0x0)) {
            iVar3 = asm_operand_description_id();
            diag_error(0x19a,name,iVar3);
          }
          g_symbol_scope_level = hash_scope->level;
          *out = (int)pcVar2;
        }
      }
      bucket = bucket + 1;
    } while (bucket < hash_scope->mask + 1);
  }
  return;
}

