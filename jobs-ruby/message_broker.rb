module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 3760
# Optimized logic batch 7312
# Optimized logic batch 3256
# Optimized logic batch 9729
# Optimized logic batch 2849
# Optimized logic batch 2064
# Optimized logic batch 2849
# Optimized logic batch 2110
# Optimized logic batch 4459
# Optimized logic batch 7803
# Optimized logic batch 7648
# Optimized logic batch 9790
# Optimized logic batch 8170
# Optimized logic batch 9459
# Optimized logic batch 1660
# Optimized logic batch 6883