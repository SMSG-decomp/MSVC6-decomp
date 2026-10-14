char __cdecl tmpl_arguments_are_concrete(int *args)

{
  c1_u16 cVar1;
  int iVar2;
  c1_type *type;
  c1_symbol *pcVar3;
  byte bVar4;
  ushort uVar5;
  
  iVar2 = *args;
  do {
    if (iVar2 == 0) {
      return '\x01';
    }
    bVar4 = *(byte *)(iVar2 + 0xc) & 3;
    if (bVar4 == 0) {
      type = *(c1_type **)(iVar2 + 0x10);
      uVar5 = tmpl_type_find_parameter(type,0,0);
      if (uVar5 != 0) {
        return '\0';
      }
      if ((type->code & 0x200) != 0) {
        if ((((((type->extra).cls)->detail).cls)->flags3f & 0x80) != 0) {
          return '\0';
        }
        cVar1 = ((type->extra).cls)->scope_index;
        if (cVar1 != 0) {
          pcVar3 = g_scope_vector->entries[(short)cVar1];
          bVar4 = pcVar3->kind;
          while ((bVar4 & 0x1f) == 4) {
            if ((((pcVar3->detail).cls)->flags3f & 0x80) != 0) {
              return '\0';
            }
            pcVar3 = g_scope_vector->entries[(short)pcVar3->scope_index];
            if (pcVar3 == (c1_symbol *)0x0) break;
            bVar4 = pcVar3->kind;
          }
        }
      }
    }
    else if ((bVar4 == 1) && ((*(byte *)(*(int *)(iVar2 + 0x10) + 2) & 8) != 0)) {
      return '\0';
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}

