int __thiscall idb_include_stack_set_size(fe_idb_include_stack *stack,uint n)

{
  fe_idb_include_state *pfVar1;
  fe_idb_region *pfVar2;
  uint uVar3;
  uint *puVar4;
  void *array;
  int iVar5;
  uint uVar6;
  uint *src_words;
  fe_idb_include_state *pfVar7;
  uint *puVar8;
  uint uVar9;
  fe_idb_class_record *pfVar10;
  uint *puVar11;
  fe_idb_include_state *pfVar12;
  uint *dst_words;
  uint *puVar13;
  uint local_8;
  
  if (n <= stack->capacity) {
LAB_10649208:
    stack->count = n;
    return 1;
  }
  uVar3 = stack->capacity * 3 >> 1;
  if (uVar3 < n) {
    uVar3 = n;
  }
  puVar4 = __2_YAPAXI_Z(uVar3 * 0x48 + 4);
  if (puVar4 != (uint *)0x0) {
    pfVar1 = (fe_idb_include_state *)(puVar4 + 1);
    *puVar4 = uVar3;
    if (-1 < (int)(uVar3 - 1)) {
      puVar8 = puVar4 + 7;
      pfVar7 = pfVar1;
      uVar9 = uVar3;
      do {
        puVar11 = puVar8 + 2;
        (pfVar7->regions).data = (fe_idb_region *)0x0;
        puVar8[-4] = 0;
        puVar8[-5] = 0;
        puVar8[-2] = 0;
        puVar8[-1] = 0xffffffff;
        *(undefined2 *)puVar8 = 0;
        *(undefined2 *)((int)puVar8 + 2) = 0;
        *(undefined1 *)(puVar8 + 1) = 0x18;
        *puVar11 = 0;
        pfVar7 = pfVar7 + 1;
        puVar8[3] = 0;
        uVar9 = uVar9 - 1;
        puVar8[4] = 0;
        puVar8[5] = 0;
        puVar8[6] = 0;
        *puVar11 = 0;
        puVar8[-3] = 0;
        pfVar10 = &g_idb_empty_class_record;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar11 = pfVar10->class_ni;
          pfVar10 = (fe_idb_class_record *)&pfVar10->first_region;
          puVar11 = puVar11 + 1;
        }
        puVar8[7] = 0;
        puVar8[8] = 0;
        puVar8[9] = 0xffffffff;
        puVar8[10] = 0;
        *(undefined1 *)(puVar8 + 0xb) = 0;
        *(undefined1 *)((int)puVar8 + 0x2d) = 0;
        puVar8 = puVar8 + 0x12;
      } while (uVar9 != 0);
    }
    if (pfVar1 != (fe_idb_include_state *)0x0) {
      if (stack->data != (fe_idb_include_state *)0x0) {
        local_8 = 0;
        if (stack->count != 0) {
          puVar4 = puVar4 + 2;
          do {
            puVar8 = (uint *)((int)puVar4 + (int)stack->data + (-4 - (int)pfVar1));
            if (puVar8 != puVar4 + -1) {
              if (puVar4[1] < puVar8[1]) {
                if ((void *)puVar4[-1] != (void *)0x0) {
                  __3_YAXPAX_Z((void *)puVar4[-1]);
                }
                uVar9 = puVar8[1];
                puVar4[1] = uVar9;
                array = __2_YAPAXI_Z(uVar9 << 4);
                if (array == (void *)0x0) {
                  array = (void *)0x0;
                }
                else {
                  vector_constructor_iterator(array,0x10,uVar9,idb_region_ctor);
                }
                puVar4[-1] = (uint)array;
                if (array == (void *)0x0) {
                  puVar4[1] = 0;
                  *puVar4 = 0;
                  goto LAB_10649144;
                }
              }
              uVar9 = puVar8[1];
              uVar6 = 0;
              *puVar4 = uVar9;
              if (uVar9 != 0) {
                iVar5 = 0;
                do {
                  src_words = (uint *)(iVar5 + *puVar8);
                  dst_words = (uint *)(iVar5 + puVar4[-1]);
                  uVar6 = uVar6 + 1;
                  iVar5 = iVar5 + 0x10;
                  *dst_words = *src_words;
                  dst_words[1] = src_words[1];
                  dst_words[2] = src_words[2];
                  dst_words[3] = src_words[3];
                } while (uVar6 < *puVar4);
              }
            }
LAB_10649144:
            puVar4[2] = puVar8[3];
            puVar4[3] = puVar8[4];
            puVar4[4] = puVar8[5];
            puVar4[5] = puVar8[6];
            puVar4[6] = puVar8[7];
            puVar11 = puVar8 + 8;
            puVar13 = puVar4 + 7;
            for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar13 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar13 = puVar13 + 1;
            }
            puVar4[0xc] = puVar8[0xd];
            puVar4[0xd] = puVar8[0xe];
            puVar4[0xe] = puVar8[0xf];
            puVar4[0xf] = puVar8[0x10];
            *(char *)(puVar4 + 0x10) = (char)puVar8[0x11];
            *(undefined1 *)((int)puVar4 + 0x41) = *(undefined1 *)((int)puVar8 + 0x45);
            local_8 = local_8 + 1;
            puVar4 = puVar4 + 0x12;
          } while (local_8 < stack->count);
        }
        pfVar7 = stack->data;
        if (pfVar7 != (fe_idb_include_state *)0x0) {
          local_8 = *(uint *)&pfVar7[-1].changed;
          pfVar12 = pfVar7 + local_8;
          if (-1 < (int)(local_8 + -1)) {
            do {
              pfVar2 = pfVar12[-1].regions.data;
              pfVar12 = pfVar12 + -1;
              if (pfVar2 != (fe_idb_region *)0x0) {
                __3_YAXPAX_Z(pfVar2);
              }
              local_8 = local_8 + -1;
            } while (local_8 != 0);
          }
          __3_YAXPAX_Z(&pfVar7[-1].changed);
        }
      }
      stack->capacity = uVar3;
      stack->data = pfVar1;
      goto LAB_10649208;
    }
  }
  return 0;
}

