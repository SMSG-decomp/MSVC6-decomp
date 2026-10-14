void __cdecl pragma_section_attribute(char *file,int fd)

{
  uint id;
  
  id = file_mtime_or_zero(fd);
  pragma_section_record(8,id,file);
  return;
}

