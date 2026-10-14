void __cdecl
import_emit_functions(void *typeinfo,void *typeattr,wchar_t *class_name,int next_vft_offset)

{
  ushort *puVar1;
  ushort uVar2;
  bool bVar3;
  ushort uVar4;
  void *pvVar5;
  long lVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  ushort *order_cursor;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  void *pvVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int local_58;
  int local_54;
  void *local_4c;
  int local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  void *local_34;
  uint local_30;
  uint local_2c;
  void *local_28;
  uint local_24;
  uint local_20;
  c1_u32 *local_1c;
  c1_u32 local_18;
  uint present_capacity;
  c1_u32 *local_10;
  c1_u32 local_c;
  uint deleted_capacity;
  uint map_count;
  
  pvVar13 = typeattr;
  iVar7 = *(int *)((int)typeattr + 0x28);
  local_48 = iVar7;
  local_34 = __2_YAPAXI_Z(0x80);
  local_30 = -(uint)(local_34 != (void *)0x0) & 0x20;
  local_2c = local_30;
  local_28 = __2_YAPAXI_Z(0x100);
  uVar4 = 0;
  local_24 = -(uint)(local_28 != (void *)0x0) & 0x20;
  local_1c = (c1_u32 *)0x0;
  present_capacity = 0;
  local_18 = 0;
  local_10 = (c1_u32 *)0x0;
  deleted_capacity = 0;
  local_c = 0;
  map_count = 0;
  local_20 = local_24;
  pvVar5 = __2_YAPAXI_Z((uint)*(ushort *)((int)pvVar13 + 0x2c) << 1);
  piVar11 = typeinfo;
  if (iVar7 == 4) {
    uVar4 = 0;
    if (*(short *)((int)pvVar13 + 0x2c) != 0) {
      do {
        *(ushort *)((int)pvVar5 + (uint)uVar4 * 2) = uVar4;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(ushort *)((int)pvVar13 + 0x2c));
    }
  }
  else {
    pvVar8 = __2_YAPAXI_Z((uint)*(ushort *)((int)pvVar13 + 0x2c) << 2);
    if (*(short *)((int)pvVar13 + 0x2c) != 0) {
      do {
        uVar12 = (uint)uVar4;
        lVar6 = (**(code **)(*piVar11 + 0x14))(piVar11,uVar12,&local_4c);
        if (lVar6 < 0) {
          diag_fatal_file(lVar6,0x54,0x166,g_import_file_as_written);
        }
        if (uVar12 != 0) {
          order_cursor = (ushort *)((int)pvVar5 + uVar12 * 2);
          piVar11 = (int *)((int)pvVar8 + uVar12 * 4 + -4);
          do {
            if (*piVar11 < (int)*(short *)((int)local_4c + 0x1c)) break;
            piVar11[1] = *piVar11;
            *order_cursor = order_cursor[-1];
            uVar12 = uVar12 - 1;
            piVar11 = piVar11 + -1;
            order_cursor = order_cursor + -1;
          } while (0 < (int)uVar12);
        }
        *(int *)((int)pvVar8 + uVar12 * 4) = (int)*(short *)((int)local_4c + 0x1c);
        *(ushort *)((int)pvVar5 + uVar12 * 2) = uVar4;
        (**(code **)(*(int *)typeinfo + 0x50))(typeinfo,local_4c);
        uVar4 = uVar4 + 1;
        pvVar13 = typeattr;
        piVar11 = typeinfo;
      } while (uVar4 < *(ushort *)((int)typeattr + 0x2c));
    }
    __3_YAXPAX_Z(pvVar8);
  }
  iVar16 = 0;
  local_54 = next_vft_offset;
  local_58 = 0;
  uVar4 = 0;
  iVar7 = next_vft_offset;
  if (*(short *)((int)pvVar13 + 0x2c) != 0) {
    do {
      puVar1 = (ushort *)((int)pvVar5 + (uint)uVar4 * 2);
      lVar6 = (**(code **)(*piVar11 + 0x14))(piVar11,(uint)*puVar1,(void **)&next_vft_offset);
      if (lVar6 < 0) {
        diag_fatal_file(lVar6,0x54,0x166,g_import_file_as_written);
      }
      if (local_48 == 4) {
        if ((*(byte *)(next_vft_offset + 0x30) & 1) == 0) {
          bVar3 = import_emit_dispatch_method(piVar11,(void *)next_vft_offset,class_name);
          if (bVar3) goto LAB_1049f5ac;
          goto LAB_1049f8b3;
        }
      }
      else {
        if (-1 < iVar7) {
          if (iVar7 < *(short *)(next_vft_offset + 0x1c)) {
            do {
              iVar16 = iVar16 + 1;
              import_emit_vtable_gap(iVar16);
              iVar7 = iVar7 + 4;
              local_58 = iVar16;
            } while (iVar7 < *(short *)(next_vft_offset + 0x1c));
          }
          iVar7 = iVar7 + 4;
          local_54 = iVar7;
        }
        import_emit_vtable_method(piVar11,(void *)next_vft_offset,class_name);
LAB_1049f5ac:
        if ((g_import_raw_interfaces_only == 0) &&
           (((uStack_40 = *(uint *)(next_vft_offset + 0x10), uStack_40 == 2 || (uStack_40 == 4)) ||
            (uStack_40 == 8)))) {
          local_4c = *(void **)next_vft_offset;
          uVar14 = (uint)local_4c & 0xffff;
          uVar10 = uVar14 % local_30;
          uStack_44 = local_30;
          uVar12 = 0xffffffff;
          uVar15 = uVar10;
          do {
            iVar7 = iset_contains((c1xx_pdb_iset *)&stack0xffffffe4,uVar15);
            if (iVar7 == 0) {
              if (uVar12 == 0xffffffff) {
                uVar12 = uVar15;
              }
              iVar7 = iset_contains((c1xx_pdb_iset *)&stack0xfffffff0,uVar15);
              if (iVar7 == 0) break;
            }
            else if (*(void **)((int)local_34 + uVar15 * 4) == local_4c) {
              uStack_3c = *(uint *)((int)local_28 + uVar15 * 8);
              uStack_38 = *(uint *)((int)local_28 + uVar15 * 8 + 4);
              goto LAB_1049f797;
            }
            uVar15 = -(uint)(uVar15 + 1 < uStack_44) & uVar15 + 1;
          } while (uVar15 != uVar10);
          uStack_38 = 0xffffffff;
          uStack_3c = 0xffffffff;
LAB_1049f797:
          pvVar13 = local_4c;
          if (uStack_40 == 2) {
            uStack_3c = (uint)*puVar1;
          }
          else {
            if (uStack_40 == 8) {
              uVar2 = *puVar1;
            }
            else {
              if (uStack_38 != 0xffffffff) goto LAB_1049f7ad;
              uVar2 = *puVar1;
            }
            uStack_38 = (uint)uVar2;
          }
LAB_1049f7ad:
          uVar14 = uVar14 % local_30;
          uStack_40 = local_30;
          uVar12 = 0xffffffff;
          uVar15 = uVar14;
          do {
            iVar9 = iset_contains((c1xx_pdb_iset *)&stack0xffffffe4,uVar15);
            iVar7 = local_54;
            iVar16 = local_58;
            if (iVar9 == 0) {
              if (uVar12 == 0xffffffff) {
                uVar12 = uVar15;
              }
              iVar9 = iset_contains((c1xx_pdb_iset *)&stack0xfffffff0,uVar15);
              if (iVar9 == 0) break;
            }
            else if (*(void **)((int)local_34 + uVar15 * 4) == pvVar13) {
              *(uint *)((int)local_28 + uVar15 * 8) = uStack_3c;
              *(uint *)((int)local_28 + uVar15 * 8 + 4) = uStack_38;
              pvVar13 = typeattr;
              piVar11 = typeinfo;
              goto LAB_1049f8b3;
            }
            uVar15 = -(uint)(uVar15 + 1 < uStack_40) & uVar15 + 1;
          } while (uVar15 != uVar14);
          if (uVar12 < local_c << 5) {
            local_10[uVar12 >> 5] = local_10[uVar12 >> 5] & ~(1 << ((byte)uVar12 & 0x1f));
          }
          iset_add((c1xx_pdb_iset *)&stack0xffffffe4,uVar12);
          *(void **)((int)local_34 + uVar12 * 4) = pvVar13;
          *(uint *)((int)local_28 + uVar12 * 8) = uStack_3c;
          *(uint *)((int)local_28 + uVar12 * 8 + 4) = uStack_38;
          map_pair_grow_if_full(&local_34);
          pvVar13 = typeattr;
          piVar11 = typeinfo;
        }
LAB_1049f8b3:
        (**(code **)(*piVar11 + 0x50))(piVar11,(void *)next_vft_offset);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(ushort *)((int)pvVar13 + 0x2c));
  }
  __3_YAXPAX_Z(pvVar5);
  if ((-1 < iVar7) && (iVar7 < (int)(uint)*(ushort *)((int)pvVar13 + 0x32))) {
    do {
      iVar16 = iVar16 + 1;
      import_emit_vtable_gap(iVar16);
      iVar7 = iVar7 + 4;
    } while (iVar7 < (int)(uint)*(ushort *)((int)pvVar13 + 0x32));
  }
  uVar12 = 0xffffffff;
  while (uVar12 = uVar12 + 1, uVar12 < local_30) {
    while ((local_18 << 5 <= uVar12 || ((local_1c[uVar12 >> 5] & 1 << ((byte)uVar12 & 0x1f)) == 0)))
    {
      uVar12 = uVar12 + 1;
      if (local_30 <= uVar12) goto LAB_1049f93f;
    }
    uVar15 = *(uint *)((int)local_28 + uVar12 * 8);
    uVar10 = *(uint *)((int)local_28 + uVar12 * 8 + 4);
    if (uVar15 == 0xffffffff) {
      typeinfo = (void *)0x0;
    }
    else {
      lVar6 = (**(code **)(*piVar11 + 0x14))(piVar11,uVar15,&typeinfo);
      if (lVar6 < 0) {
        diag_fatal_file(lVar6,0x54,0x166,g_import_file_as_written);
      }
    }
    if (uVar10 == 0xffffffff) {
      typeattr = (void *)0x0;
    }
    else {
      lVar6 = (**(code **)(*piVar11 + 0x14))(piVar11,uVar10,&typeattr);
      if (lVar6 < 0) {
        diag_fatal_file(lVar6,0x54,0x166,g_import_file_as_written);
      }
    }
    import_emit_property_declspec(piVar11,typeinfo,typeattr,class_name);
    if (typeinfo != (void *)0x0) {
      (**(code **)(*piVar11 + 0x50))(piVar11,typeinfo);
    }
    if (typeattr != (void *)0x0) {
      (**(code **)(*piVar11 + 0x50))(piVar11,typeattr);
    }
  }
LAB_1049f93f:
  if (local_10 != (c1_u32 *)0x0) {
    __3_YAXPAX_Z(local_10);
  }
  if (local_1c != (c1_u32 *)0x0) {
    __3_YAXPAX_Z(local_1c);
  }
  if (local_28 != (void *)0x0) {
    __3_YAXPAX_Z(local_28);
  }
  if (local_34 != (void *)0x0) {
    __3_YAXPAX_Z(local_34);
  }
  return;
}

