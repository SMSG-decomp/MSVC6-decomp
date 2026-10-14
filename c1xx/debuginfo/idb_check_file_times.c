int __fastcall idb_check_file_times(c1xx_idb *idb)

{
  c1xx_pdb_map *map;
  c1xx_pdb_iset *set;
  c1_u32 *pcVar1;
  uint *puVar2;
  uint uVar3;
  c1_u32 cVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_3c;
  char *file_name;
  uint uStack_34;
  uint local_28;
  c1_stat stat_buf;
  
  map = &idb->old_file_times;
  uVar9 = 0xffffffff;
LAB_1048e66f:
  do {
    do {
      uVar3 = (idb->old_file_times).domain.count;
      uVar9 = uVar9 + 1;
      if (uVar3 <= uVar9) {
        return 1;
      }
      while (((idb->old_file_times).present.count << 5 <= uVar9 ||
             (((idb->old_file_times).present.data[uVar9 >> 5] & 1 << ((byte)uVar9 & 0x1f)) == 0))) {
        uVar9 = uVar9 + 1;
        if (uVar3 <= uVar9) {
          return 1;
        }
      }
      cVar4 = (idb->old_file_times).range.data[uVar9];
      uVar3 = (map->domain).data[uVar9];
      local_28 = uVar9;
      iVar6 = (*idb->name_map->vtbl->get_name)(uVar3,&file_name);
      if (iVar6 == 0) {
        return 0;
      }
      stat_buf.st_mtime = -1;
      iVar6 = stat(file_name,&stat_buf);
    } while ((iVar6 == 0) && (cVar4 == stat_buf.st_mtime));
    iVar6 = (*idb->vtbl->idb_invalidate)(idb);
    lVar5 = stat_buf.st_mtime;
    if (iVar6 == 0) {
      return 0;
    }
    if (stat_buf.st_mtime != -1) {
      uVar9 = (idb->old_file_times).domain.count;
      uVar7 = (uVar3 & 0xffff) % uVar9;
      uVar8 = 0xffffffff;
      uStack_34 = uVar7;
      do {
        iVar6 = iset_contains(&(idb->old_file_times).present,uVar7);
        if (iVar6 == 0) {
          if (uVar8 == 0xffffffff) {
            uVar8 = uVar7;
          }
          iVar6 = iset_contains(&(idb->old_file_times).deleted,uVar7);
          if (iVar6 == 0) break;
        }
        else if ((map->domain).data[uVar7] == uVar3) {
          (idb->old_file_times).range.data[uVar7] = lVar5;
          uVar9 = local_28;
          goto LAB_1048e66f;
        }
        uVar7 = -(uint)(uVar7 + 1 < uVar9) & uVar7 + 1;
      } while (uVar7 != uStack_34);
      if (uVar8 < (idb->old_file_times).deleted.count << 5) {
        puVar2 = (idb->old_file_times).deleted.data + (uVar8 >> 5);
        *puVar2 = *puVar2 & ~(1 << ((byte)uVar8 & 0x1f));
      }
      set = &(idb->old_file_times).present;
      iVar6 = iset_ensure_room(set,uVar8);
      if (iVar6 != 0) {
        puVar2 = set->data + (uVar8 >> 5);
        *puVar2 = *puVar2 | 1 << ((byte)uVar8 & 0x1f);
      }
      (map->domain).data[uVar8] = uVar3;
      (idb->old_file_times).range.data[uVar8] = lVar5;
      map_grow_2(map);
      uVar9 = local_28;
      goto LAB_1048e66f;
    }
    uStack_34 = (idb->old_file_times).domain.count;
    uVar7 = (uVar3 & 0xffff) % uStack_34;
    local_3c = 0xffffffff;
    uVar8 = uVar7;
    do {
      iVar6 = iset_contains(&(idb->old_file_times).present,uVar8);
      if (iVar6 == 0) {
        if (local_3c == 0xffffffff) {
          local_3c = uVar8;
        }
        iVar6 = iset_contains(&(idb->old_file_times).deleted,uVar8);
        if (iVar6 == 0) break;
      }
      else if ((map->domain).data[uVar8] == uVar3) {
        iset_remove(&(idb->old_file_times).present,uVar8);
        iset_add(&(idb->old_file_times).deleted,uVar8);
        pcVar1 = &(idb->old_file_times).count;
        *pcVar1 = *pcVar1 - 1;
        break;
      }
      uVar8 = -(uint)(uVar8 + 1 < uStack_34) & uVar8 + 1;
    } while (uVar8 != uVar7);
  } while( true );
}

