c1xx_idb * __thiscall
idb_construct(c1xx_idb *idb,c1xx_pdb *pdb,c1xx_pdb *pdb_backup,c1_pdb_namemap *name_map,
             c1xx_source_tracker_iface *source_tracker,int incremental,int backup_on_write,
             int read_from_backup)

{
  uint *src;
  uint *src_2;
  uint *src_3;
  int iVar1;
  uint *dst;
  c1_idb_class_record *pcVar2;
  c1xx_idb *local_4;
  
  idb->vtbl = (c1xx_idb_vtbl *)&PTR__purecall_104cafc4;
  (idb->include_stack).data = (c1_idb_include_state *)0x0;
  (idb->include_stack).capacity = 0;
  (idb->include_stack).count = 0;
  local_4 = idb;
  src = __2_YAPAXI_Z(4);
  (idb->old_file_times).domain.data = src;
  (idb->old_file_times).domain.capacity = (uint)(src != (uint *)0x0);
  (idb->old_file_times).domain.count = (uint)(src != (uint *)0x0);
  array_init_count(&(idb->old_file_times).range,1);
  il_buffer_init_empty((int *)&(idb->old_file_times).present);
  il_buffer_init_empty((int *)&(idb->old_file_times).deleted);
  (idb->old_file_times).count = 0;
  src_2 = __2_YAPAXI_Z(4);
  (idb->header_times).domain.data = src_2;
  (idb->header_times).domain.capacity = (uint)(src_2 != (uint *)0x0);
  (idb->header_times).domain.count = (uint)(src_2 != (uint *)0x0);
  array_init_count(&(idb->header_times).range,1);
  il_buffer_init_empty((int *)&(idb->header_times).present);
  il_buffer_init_empty((int *)&(idb->header_times).deleted);
  (idb->header_times).count = 0;
  src_3 = __2_YAPAXI_Z(4);
  (idb->header_signatures).domain.data = src_3;
  (idb->header_signatures).domain.capacity = (uint)(src_3 != (uint *)0x0);
  (idb->header_signatures).domain.count = (uint)(src_3 != (uint *)0x0);
  array_init_count(&(idb->header_signatures).range,1);
  il_buffer_init_empty((int *)&(idb->header_signatures).present);
  il_buffer_init_empty((int *)&(idb->header_signatures).deleted);
  (idb->header_signatures).count = 0;
  (idb->file).regions.data = (c1_idb_region *)0x0;
  (idb->file).regions.capacity = 0;
  (idb->file).regions.count = 0;
  gi_region_entry_init(&(idb->file).current,0);
  pcVar2 = &(idb->file).pending_class;
  pcVar2->class_ni = 0;
  (idb->file).pending_class.first_region = 0;
  (idb->file).pending_class.unk08 = 0;
  (idb->file).pending_class.depth = 0;
  (idb->file).pending_class.change = 0;
  pcVar2->class_ni = 0;
  (idb->file).cursor = 0;
  iVar1 = 5;
  dst = &g_idb_empty_class_record.class_ni;
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2->class_ni = *dst;
    dst = dst + 1;
    pcVar2 = (c1_idb_class_record *)&pcVar2->first_region;
  }
  (idb->file).tracker = (c1_mre_file *)0x0;
  (idb->file).name_ni = 0;
  (idb->file).mtime = -1;
  (idb->file).unk40 = 0;
  (idb->file).changed = '\0';
  (idb->file).untracked = '\0';
  (idb->browse_lines).data = (c1_idb_browse_entry *)0x0;
  (idb->browse_lines).capacity = 0;
  (idb->browse_lines).count = 0;
  array_init_count(&idb->name_hash_bits,0x200);
  local_4 = (c1xx_idb *)0x0;
  dword_array_fill(&idb->name_hash_bits,(c1_u32 *)&local_4);
  map_init(&idb->file_times,1);
  idb->pdb = pdb;
  idb->pdb_backup = pdb_backup;
  idb->name_map = name_map;
  idb->source_tracker = source_tracker;
  idb->options_signature = -1;
  idb->unk130 = -1;
  idb->incremental = incremental;
  idb->vtbl = (c1xx_idb_vtbl *)&PTR_idb_commit_104caedc;
  idb->deps_stream = (c1xx_pdb_stream *)0x0;
  idb->deps_stream_backup = (c1xx_pdb_stream *)0x0;
  idb->module_stream = (c1xx_pdb_stream *)0x0;
  idb->module_stream_backup = (c1xx_pdb_stream *)0x0;
  idb->backup_on_write = backup_on_write;
  idb->read_from_backup = read_from_backup;
  idb->state = 1;
  idb->force_recompile = 0;
  idb->cond_depth = 0;
  idb->invalidated = 0;
  idb->reused = 0;
  idb->helper_called = '\0';
  idb->regions_disabled = '\0';
  idb->pch_generation_loaded = 0;
  idb->pch_generation = 0;
  idb->regions_pch_generation = 0;
  idb->browse_size = 0;
  idb->in_function = '\0';
  idb->pdb_signature = 0;
  idb->pdb_age = 0;
  return idb;
}

