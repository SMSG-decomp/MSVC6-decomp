int __thiscall idb_include_stack_set_size(c1_idb_include_stack *stack,uint count)

{
  c1_idb_include_state *pcVar1;
  c1_idb_region *pcVar2;
  uint uVar3;
  uint *puVar4;
  void *array;
  int iVar5;
  uint uVar6;
  c1_u32 *src_entry;
  c1_idb_include_state *pcVar7;
  uint *puVar8;
  uint uVar9;
  c1_idb_class_record *pcVar10;
  uint *puVar11;
  c1_idb_include_state *pcVar12;
  uint *dst;
  uint *puVar13;
  uint local_8;
  
  if (count <= stack->capacity) {
LAB_10491b47:
    stack->count = count;
    return 1;
  }
  uVar3 = stack->capacity * 3 >> 1;
  if (uVar3 < count) {
    uVar3 = count;
  }
  puVar4 = __2_YAPAXI_Z(uVar3 * 0x48 + 4);
  if (puVar4 != (uint *)0x0) {
    pcVar1 = (c1_idb_include_state *)(puVar4 + 1);
    *puVar4 = uVar3;
    if (-1 < (int)(uVar3 - 1)) {
      puVar8 = puVar4 + 7;
      pcVar7 = pcVar1;
      uVar9 = uVar3;
      do {
        puVar11 = puVar8 + 2;
        (pcVar7->regions).data = (c1_idb_region *)0x0;
        puVar8[-4] = 0;
        puVar8[-5] = 0;
        puVar8[-2] = 0;
        puVar8[-1] = 0xffffffff;
        *(undefined2 *)puVar8 = 0;
        *(undefined2 *)((int)puVar8 + 2) = 0;
        *(undefined1 *)(puVar8 + 1) = 0x18;
        *puVar11 = 0;
        pcVar7 = pcVar7 + 1;
        puVar8[3] = 0;
        uVar9 = uVar9 - 1;
        puVar8[4] = 0;
        puVar8[5] = 0;
        puVar8[6] = 0;
        *puVar11 = 0;
        puVar8[-3] = 0;
        pcVar10 = &g_idb_empty_class_record;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar11 = pcVar10->class_ni;
          pcVar10 = (c1_idb_class_record *)&pcVar10->first_region;
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
    if (pcVar1 != (c1_idb_include_state *)0x0) {
      if (stack->data != (c1_idb_include_state *)0x0) {
        local_8 = 0;
        if (stack->count != 0) {
          puVar4 = puVar4 + 2;
          do {
            puVar8 = (uint *)((int)puVar4 + (int)stack->data + (-4 - (int)pcVar1));
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
                  vector_constructor_iterator(array,0x10,uVar9,gi_region_entry_init_empty);
                }
                puVar4[-1] = (uint)array;
                if (array == (void *)0x0) {
                  puVar4[1] = 0;
                  *puVar4 = 0;
                  goto LAB_10491a83;
                }
              }
              uVar9 = puVar8[1];
              uVar6 = 0;
              *puVar4 = uVar9;
              if (uVar9 != 0) {
                iVar5 = 0;
                do {
                  src_entry = (c1_u32 *)(iVar5 + *puVar8);
                  dst = (uint *)(iVar5 + puVar4[-1]);
                  uVar6 = uVar6 + 1;
                  iVar5 = iVar5 + 0x10;
                  *dst = *src_entry;
                  dst[1] = src_entry[1];
                  dst[2] = src_entry[2];
                  dst[3] = src_entry[3];
                } while (uVar6 < *puVar4);
              }
            }
LAB_10491a83:
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
        pcVar7 = stack->data;
        if (pcVar7 != (c1_idb_include_state *)0x0) {
          local_8 = *(uint *)&pcVar7[-1].changed;
          pcVar12 = pcVar7 + local_8;
          if (-1 < (int)(local_8 + -1)) {
            do {
              pcVar2 = pcVar12[-1].regions.data;
              pcVar12 = pcVar12 + -1;
              if (pcVar2 != (c1_idb_region *)0x0) {
                __3_YAXPAX_Z(pcVar2);
              }
              local_8 = local_8 + -1;
            } while (local_8 != 0);
          }
          __3_YAXPAX_Z(&pcVar7[-1].changed);
        }
      }
      stack->capacity = uVar3;
      stack->data = pcVar1;
      goto LAB_10491b47;
    }
  }
  return 0;
}

