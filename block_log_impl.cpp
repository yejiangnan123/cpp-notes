//管理区块日志
namespace detail {
      class block_log_impl {
         public:
            signed_block_ptr         head;
            block_id_type            head_id;
            std::fstream             block_stream;  //区块文件流
            std::fstream             index_stream;  //索引文件流
            fc::path                 block_file;    //区块文件路径
            fc::path                 index_file;    //区块文件路径
            bool                     block_write;
            bool                     index_write;
            bool                     genesis_written_to_block_log = false;
            uint32_t                 version = 0;
            uint32_t                 first_block_num = 0;

            inline void check_block_read() {
               if (block_write) {
                  block_stream.close();
                  block_stream.open(block_file.generic_string().c_str(), LOG_READ);
                  block_write = false;
               }
            }

            inline void check_block_write() {
               if (!block_write) {
                  block_stream.close();
                  block_stream.open(block_file.generic_string().c_str(), LOG_WRITE);
                  block_write = true;
               }
            }

            inline void check_index_read() {
               try {
                  if (index_write) {
                     index_stream.close();
                     index_stream.open(index_file.generic_string().c_str(), LOG_READ);
                     index_write = false;
                  }
               }
               FC_LOG_AND_RETHROW()
            }

            inline void check_index_write() {
               if (!index_write) {
                  index_stream.close();
                  index_stream.open(index_file.generic_string().c_str(), LOG_WRITE);
                  index_write = true;
               }
            }
      };
   }
