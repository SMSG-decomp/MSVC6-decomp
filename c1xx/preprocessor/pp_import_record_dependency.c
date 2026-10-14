void __cdecl pp_import_record_dependency(char *file)

{
  uint id;
  
  id = file_mtime(file);
  pragma_section_record(8,id,file);
  return;
}

