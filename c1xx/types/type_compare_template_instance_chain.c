int __cdecl type_compare_template_instance_chain(c1_type *a,c1_type *b)

{
  c1_type *pcVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  int *piVar7;
  c1_symbol *pcVar8;
  int iVar9;
  c1_symbol *key;
  
  iVar9 = 0;
  if (a != b) {
    do {
      uVar3 = a->code;
      if (((uVar3 ^ b->code) & 0x3fff) != 0) {
        return 2;
      }
      if ((iVar9 != 0) && (a->flags != b->flags)) {
        return 2;
      }
      pcVar8 = (a->extra).cls;
      if (pcVar8 != (b->extra).cls) {
        if ((uVar3 & 0x300) == 0) {
          if (-1 < (char)(byte)uVar3) {
            return 2;
          }
          if (((byte)uVar3 & 0x8f) != 0x80) {
            return 2;
          }
          pcVar1 = a->base;
          iVar4 = type_is_class_or_enum(pcVar1);
          if ((char)iVar4 == '\0') {
            return 2;
          }
          pcVar8 = (pcVar1->extra).cls;
        }
        if ((b->code & 0x300) == 0) {
          bVar2 = (byte)b->code;
          if (-1 < (char)bVar2) {
            return 2;
          }
          if ((bVar2 & 0x8f) != 0x80) {
            return 2;
          }
          pcVar1 = b->base;
          iVar4 = type_is_class_or_enum(pcVar1);
          if ((char)iVar4 == '\0') {
            return 2;
          }
          key = (pcVar1->extra).cls;
        }
        else {
          key = (b->extra).cls;
        }
        if ((((pcVar8->detail).cls)->flags3e & 1) == 0) {
          return 2;
        }
        bVar2 = ((key->detail).cls)->flags3e;
        if ((bVar2 & 1) == 0) {
          if ((g_compile_flags_cc & 0x200000) == 0) {
            return 2;
          }
          if ((bVar2 & 2) == 0) {
            return 2;
          }
          pcVar8 = tmpl_template_of_instance(pcVar8);
          if (key != pcVar8) {
            return 2;
          }
        }
        else {
          pvVar5 = tmpl_template_of_instance(pcVar8);
          pvVar6 = tmpl_template_of_instance(key);
          if (pvVar5 != pvVar6) {
            return 2;
          }
          piVar7 = symtab_15f4_lookup(key);
          iVar4 = *piVar7;
          do {
            bVar2 = *(byte *)(iVar4 + 0xc) & 3;
            if (bVar2 == 0) {
              uVar3 = tmpl_type_find_parameter(*(c1_type **)(iVar4 + 0x10),1,0);
              if (uVar3 == 0) {
                return 2;
              }
            }
            else if ((bVar2 == 1) && ((*(byte *)(*(int *)(iVar4 + 0x10) + 2) & 8) == 0)) {
              return 2;
            }
            iVar4 = *(int *)(iVar4 + 4);
          } while (iVar4 != 0);
        }
      }
      bVar2 = (byte)a->code;
      if (-1 < (char)bVar2) {
        return 0;
      }
      if (((bVar2 ^ (byte)b->code) & 0x8f) != 0) {
        return 2;
      }
      a = a->base;
      b = b->base;
      iVar9 = iVar9 + 1;
    } while (a != b);
  }
  return 0;
}

