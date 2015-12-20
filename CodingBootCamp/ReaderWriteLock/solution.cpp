class ReaderWriterLock{
  private:
      pthread_mutex_lock lock;
      pthread_cond_t reader_gate;
      pthread_cond_t writer_gate;
      int reader;
      int writer;
      int wait_writer; 
   public:
     ReaderWriterLock(){
        wait_writer = 0;
        write = 0;
        reader = 0; 
     }

     void reader_lock(){
        pthread_mutex_lock(&lock);
        
        while(writer > 0){
          pthread_cont_wait(&reader_gate, &lock);
        } 
        reader++; 
        pthread_mutex_unlock(&lock);  
     }

    void reader_unlock(){
      pthread_mutex_lock(&lock);
      reader--;
      if(reader == 0 && wait_writer > 0){
        pthread_cont_signal(&writer_gate, &lock);
      }
      pthread_mutex_unlock(&lock);
    }

    void writer_lock(){
      pthread_mutex_lock(&lock);
      wait_writer++;
      while(readeer > 0 || wirter > 0){
          pthread_cont_wait(&write_gate, &lock);
      }
      writer++;
      wait_writer--; 
      pthread_mutex_unlock(&lock);
    }

    void write_unlock(){
      pthread_mutex_lock(&lock);
      writer--;
      if(wait_writer > 0){
        pthread_cont_signal(&writer_gate, &lock);
      }else{
        pthread_cond_broadcast(&reader_gate, &lock);
      }

      pthread_mutex_unlock(&lock);
    } 
};
